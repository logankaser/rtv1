/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:13:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/28 17:34:54 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Exception!\n");exit(1)
#include "wrapper.h"
#include "rtv1.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

/*
** Currently hardcoded for a sphere of radius 0.5 at 0, 0, 0
*/

unsigned	trace(t_vec3 ori, t_vec3 dir, t_rt *rt)
{
	(void)rt;
	const double r = 0.5;
	t_vec3 oc = V3_MINUS_V3(ori, V3(0, 0, 0));
    const double b = 2 * V3_DOT(oc, dir);
    const double c = V3_DOT(oc, oc) - r*r;
    double disc = b*b - 4 * c;
    if (disc < 0.0001)
		return (0x000000);
    //disc = sqrt(disc);
    //const double t0 = -b - disc;
    //const double t1 = -b + disc;
    //double t = (t0 < t1) ? t0 : t1;
	return 0xFF4F4F;
}

t_rt		*init(void)
{
	t_rt	*rt;

	rt = malloc(sizeof(rt));
	rt->c = context_new();
	rt->cam = mat_new(4);
	look_at(V3(1, 0, 1), V3(0, 0, 0), rt->cam);
	rt->scale = tan(FOV * 0.5 * (M_PI / 180));
	rt->aspect =  WIN_X / WIN_Y;
	return (rt);
}

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
			dir = V3((2 * (x + 0.5) / (double)WIN_X - 1) * rt->scale * rt->aspect,
			(1 - 2 * (y + 0.5) / (double)WIN_Y) * rt->scale, -1);
			dir = vec3_normalize(vec3_x_mat(dir, rt->cam));
			buffer_point(rt->c->buffs->content, x, y,
				trace(ori, dir, rt));
		}
	}
	blit_all(rt->c);
	mlx_loop(rt->c->mlx);
	return (0);
}
