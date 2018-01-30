/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:13:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/29 18:59:30 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Exception!\n");exit(1)
#include "rtv1.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

unsigned	shade(t_ray *ray, t_rt *rt, t_obj *hit_obj, double hit_dis)
{
	(void)ray;
	(void)hit_dis;
	(void)rt;
	return (hit_obj->color);
}

unsigned	trace(t_ray *ray, t_rt *rt)
{
	t_list	*objs;
	t_obj	*obj;
	double	dis;
	t_obj	*hit_obj;
	double	hit_dis;

	hit_obj = NULL;
	hit_dis = INFINITY;
	objs = rt->objs;
	while (objs)
	{
		dis = INFINITY;
		obj = objs->content;
		MATCH(obj->type == t_sphere, trace_sphere(ray, obj, &dis));
		//OR(obj->type == t_plane, trace_plane(ray, obj, &dis));
		//OR(obj->type == t_cylinder, trace_cylinder(ray, obj, &dis));
		//OR(obj->type == t_cone, trace_cone(ray, obj, &dis));
		if (dis < INFINITY && dis < hit_dis)
		{
			hit_dis = dis;
			hit_obj = obj;
		}
		objs = objs->next;
	}
	return (hit_obj ? shade(ray, rt, hit_obj, hit_dis) : 0x000000);
}

void		init(t_rt *rt)
{
	t_obj	*example;
	t_obj	*example2;

	rt->c = context_new();
	rt->cam.order = 4;
	look_at(V3(4, 0, 0), V3(0, 0, 0), &rt->cam);
	rt->scale = tan(FOV * 0.5 * (M_PI / 180));
	rt->objs = NULL;
	ASSERT((example = malloc(sizeof(t_obj))));
	example->position = V3(0, 0, 0);
	example->type = t_sphere;
	example->radius = 0.5;
	example->color = 0xFF0000;
	ft_lstpush(&rt->objs, example, sizeof(t_obj));
	ASSERT((example2 = malloc(sizeof(t_obj))));
	example2->position = V3(0, 0.5, 0);
	example2->type = t_sphere;
	example2->radius = 0.6;
	example2->color = 0x0000FF;
	ft_lstpush(&rt->objs, example2, sizeof(t_obj));
}

int			main(void)
{
	int		x;
	int		y;
	t_ray	ray;
	t_rt	rt;

	init(&rt);
	ray.o = vec3_x_mat(V3(0, 0, -20), &rt.cam);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			ray.d = V3((2 * (x + 0.5) / (double)WIN_X - 1) * rt.scale,
			(1 - 2 * (y + 0.5) / (double)WIN_Y) * rt.scale, -1);
			ray.d = vec3_normalize(vec3_x_mat(ray.d, &rt.cam));
			buffer_point(rt.c->buffs->content, x, y, trace(&ray, &rt));
		}
	}
	blit_all(rt.c);
	mlx_loop(rt.c->mlx);
	return (0);
}
