/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:13:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/25 15:30:52 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Exception!\n");exit(1)
#include "wrapper.h"
#include "rtv1.h"
#include <fcntl.h>
#include <math.h>

unsigned	trace(t_vec3 ori, t_vec3 dir, t_rt *rt)
{
	double	thc;
	double	tca;
	double	d2;
	double radius2;
	t_vec3	l;

	(void)rt;
	radius2 = 0.5 * 0.5;
	l = V3_MINUS_V3(V3(0, 0, 0), ori);
	tca = V3_DOT(l, dir);
	//if (tca < 0)
	//	return (0x000000);
	d2 = V3_DOT(l, dir) - tca * tca;
	//if (d2 > radius2)
	//	return (0x000000);
	thc = sqrt(radius2 - d2);
	if (tca - thc < 0 || tca + thc < 0)
		return (0x000000);
	return (0xFFFFFF);
}

t_rt		*init(void)
{
	t_rt	*rt;

	rt = malloc(sizeof(rt));
	rt->c = context_new();
	rt->cam = mat_new(4);
	look_at(V3(1, 1, 0), V3(0, 0, 0), rt->cam);
	rt->scale = tan(M_PI * 0.5 * FOV / 180.);
	return (rt);
}

#include <stdlib.h>

int			main(void)
{
	int		x;
	int		y;
	t_vec3	dir;
	t_vec3	ori;
	t_rt	*rt;

	rt = init();
	ori = vec3_x_mat(V3(0, 0, 0), rt->cam);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			dir = V3((2 * (((x + 0.5) * (1 / (double)WIN_X)) - 1))
			* rt->scale * (WIN_X / (double)WIN_Y),
			(1 - 2 * ((y + 0.5) * (1 / (double)WIN_Y))) * rt->scale, -1);
			dir = vec3_normalize(vec3_x_mat(dir, rt->cam));
			buffer_point(rt->c->buffs->content, x, y,
				trace(ori, dir, rt));
		}
	}
	blit_all(rt->c);
	mlx_loop(rt->c->mlx);
	return (0);
}
