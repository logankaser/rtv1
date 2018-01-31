/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:13:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/31 12:45:39 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Exception!\n");exit(1)
#include "rtv1.h"

unsigned	color_mult(unsigned c, const float x)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	b = (c & 0xFF) * x;
	g = (c >> 8 & 0xFF) * x;
	r = (c >> 16 & 0xFF) * x;
	return (RGB(r, g, b));
}

unsigned	shade(t_ray ray, t_rt *rt, t_obj *hit_obj, double hit_dis)
{
	(void)rt;
	t_vec3	normal;

	vec3_mult(&ray.d, hit_dis);
	t_vec3 hp = V3_PLUS_V3(ray.o, ray.d);
	vec3_normalize(&hp);

	if (hit_obj->type == t_sphere)
		normal = V3_MINUS_V3(hp, hit_obj->position);
	else
		normal = hit_obj->rotation;
	vec3_normalize(&normal);
	t_vec3 light_dir = V3_MINUS_V3(hp, V3(0, -7, 0));
	double fac = (1 / 3.0) * V3_DOT(normal, light_dir);
	if (fac < 0)
		fac = 0;
	fac += 0.1;
	if (fac > 1)
		fac = 1;
	return (color_mult(hit_obj->color, fac));
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
		MATCH(obj->type == t_sphere, intersect_sphere(*ray, obj, &dis));
		OR(obj->type == t_plane, intersect_plane(*ray, obj, &dis));
		//OR(obj->type == t_cylinder, intersect_cylinder(ray, obj, &dis));
		//OR(obj->type == t_cone, intersect_cone(ray, obj, &dis));
		if (dis < INFINITY && dis < hit_dis)
		{
			hit_dis = dis;
			hit_obj = obj;
		}
		objs = objs->next;
	}
	return (hit_obj ? shade(*ray, rt, hit_obj, hit_dis) : 0x000000);
}

void		init(t_rt *rt, int ac, char **av)
{
	/*t_obj	*ex;
	t_obj	*ex1;
	t_obj	*ex2;

	rt->c = context_new();
	rt->cam.order = 4;
	look_at(V3(5, 0, 0), V3(0, 0, 0), &rt->cam);
	rt->scale = tan(FOV * 0.5 * (M_PI / 180));
	rt->objs = NULL;
	ASSERT((ex = malloc(sizeof(t_obj))));
	ex->position = V3(0, 0.2, 0);
	ex->type = t_sphere;
	ex->radius = 0.5;
	ex->color = 0xFF0000;
	ft_lstpush(&rt->objs, ex, sizeof(t_obj));
	ASSERT((ex1 = malloc(sizeof(t_obj))));
	ex1->position = V3(0, 0, 1);
	ex1->type = t_sphere;
	ex1->radius = 0.6;
	ex1->color = 0x00FF00;
	ft_lstpush(&rt->objs, ex1, sizeof(t_obj));
	ASSERT((ex2 = malloc(sizeof(t_obj))));
	ex2->position = V3(0, -0.5, 0);
	ex2->type = t_plane;
	ex2->radius = 0;
	ex2->rotation = V3(0, 1, 0.3);
	ex2->color = 0xFFFF00;
	ft_lstpush(&rt->objs, ex2, sizeof(t_obj));
	*/
	if (ac != 2)
	{
		ft_putendl("No scene selected or too many files.");
		exit(0);
	}
	rt->c = context_new();
	rt->cam.order = 4;
	rt->scale = tan(FOV * 0.5 * (M_PI / 180));
	rt->objs = NULL;
	parse(av[1], rt);
}

int			main(int ac, char **av)
{
	int		x;
	int		y;
	t_ray	ray;
	t_rt	rt;

	init(&rt, ac, av);
	ray.o = vec3_x_mat(V3(0, 0, 0), &rt.cam);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			ray.d = V3((2 * (x + 0.5) / (double)WIN_X - 1) * rt.scale,
			(1 - 2 * (y + 0.5) / (double)WIN_Y) * rt.scale, -1);
			ray.d = dir3_x_mat(ray.d, &rt.cam);
			vec3_normalize(&ray.d);
			buffer_point(rt.c->buffs->content, x, y, trace(&ray, &rt));
		}
	}
	blit_all(rt.c);
	mlx_hook(rt.c->win, 2, 0, hook_keys, rt.c);
	mlx_loop(rt.c->mlx);
	return (0);
}
