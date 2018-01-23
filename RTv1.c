/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:44:27 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/22 16:00:30 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Error reading map.\n");exit(1)
#include "wrapper.h"
#include "fdf.h"
#include <fcntl.h>
#include <math.h>

static t_bool	project(t_mat *to_view, t_vec3 pos, t_vec2 *raster)
{
	pos = vec3_x_mat(pos, to_view);
	pos.x /= -pos.z;
	pos.y /= -pos.z;
	if (fabsf(pos.x) >= CANVAS_X / 2.01 || fabsf(pos.y) >= CANVAS_Y / 2.01)
		return (0);
	raster->x = ((pos.x + CANVAS_X * 0.5) / CANVAS_X) * WIN_X;
	raster->y = (1 - ((pos.y + CANVAS_Y * 0.5) / CANVAS_Y)) * WIN_Y;
	return (1);
}

int				draw(t_map *map)
{
	t_mat	world;
	t_vec2	a;
	t_vec2	b;
	t_list	*r;
	int		i;

	r = map->data;
	world = *map->c->view;
	while (r)
	{
		i = -1;
		while (++i < map->width)
		{
			if (!project(&world, ((t_vec3*)r->content)[i], &a))
				continue;
			if (i + 1 < map->width
				&& project(&world, ((t_vec3*)r->content)[i + 1], &b))
				draw_line(map->c->buffs->content, a, b, 0x0F0FFF);
			if (r->next && project(&world, ((t_vec3*)r->next->content)[i], &b))
				draw_line(map->c->buffs->content, a, b, 0xFF0F0F);
		}
		r = r->next;
	}
	blit_all(map->c);
	return (0);
}

int				main(int argc, char **argv)
{
	t_ctx	*c;
	t_map	*map;

	if (argc == 2)
	{
		map = read_map(argv[1]);
		c = initalize();
		map->c = c;
		ft_lstpush(&c->buffs, buffer_new(c, WIN_X, WIN_Y), sizeof(t_buff));
		mlx_loop_hook(c->mlx, draw, map);
		mlx_loop(c->mlx);
	}
}
