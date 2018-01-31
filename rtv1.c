/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:13:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/31 13:39:16 by lkaser           ###   ########.fr       */
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
	MATCH(hit_obj->type == t_sphere, normal = normal_sphere(hit_obj, hp));
	OR(hit_obj->type == t_plane, normal = normal_plane(hit_obj, hp));
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
