/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:13:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/24 13:54:31 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Exception!\n");exit(1)
#include "wrapper.h"
#include "rtv1.h"
#include <fcntl.h>
#include <math.h>

unsigned	trace(t_vec3 ori, t_vec3 dir, t_rt *rt)
{
	(void)ori;
	(void)dir;
	(void)rt;
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
			dir.x = (2 * (((x + 0.5) * (1 / (double)WIN_X)) - 1))
				* rt->scale * (WIN_X / (double)WIN_Y);
			dir.y = (1 - 2 * ((y + 0.5) * (1 / (double)WIN_Y))) * rt->scale;
			dir.z = -1;
			dir = vec3_normalize(vec3_x_mat(dir, rt->cam));
			buffer_point(rt->c->buffs->content, x, y,
				trace(ori, dir, rt));
		}
	}
	blit_all(rt->c);
	mlx_loop(rt->c->mlx);
	return (0);
}
