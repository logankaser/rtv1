/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:13:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/23 21:00:24 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Exception!\n");exit(1)
#include "wrapper.h"
#include "rtv1.h"
#include <fcntl.h>
#include <math.h>

unsigned	trace(t_vec3 ori, t_vec3 dir, t_list* objs, t_list* lights)
{
	(void)ori;
	(void)dir;
	(void)objs;
	(void)lights;
	return (0xFFFFFF);
}

int			main(void)
{
	int		px;
	int		py;
	double	angle;
	double	x;
	double	y;
	t_vec3	ray_dir;
	t_vec3	ray_ori;
	t_mat	*cam;
	t_buff	*b;
	t_ctx	*c;

	c = initalize();
	b = buffer_new(c, WIN_X, WIN_Y);
	cam = mat_new(4);
	look_at(V3(1, 1, 0), V3(0, 0, 0), cam);
	ray_ori = vec3_x_mat(V3(0, 0, 0), cam);
	angle = tan(M_PI * 0.5 * FOV / 180.);
	py = -1;
	while (++py < WIN_Y)
	{
		px = -1;
		while (++px < WIN_X)
		{
			x = (2 * (((px + 0.5) * (1 / (double)WIN_X)) - 1))
				* angle * (WIN_X / WIN_Y);
			y = (1 - 2 * ((py + 0.5) * (1 / (double)WIN_Y))) * angle;
			ray_dir = vec3_normalize(vec3_x_mat(V3(x, y, -1), cam));
			buffer_point(b, px, py, trace(ray_ori, ray_dir, 0, 0));
		}
	}
	buffer_blit(b, 0, 0);
	mlx_loop(c->mlx);
	return (0);
}
