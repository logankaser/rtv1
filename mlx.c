/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:44:27 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/29 19:09:16 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Error initializing libmlx!");exit(1)
#include "rtv1.h"

int			hook_keys(int key, t_rt *rt)
{
	if (key == 53)
	{
		mlx_destroy_window(rt->c->mlx, rt->c->win);
		free(rt->c->mlx);
		free(rt->c);
		exit(0);
	}
	return (0);
}

t_ctx		*context_new(void)
{
	t_ctx	*c;

	ASSERT(c = malloc(sizeof(t_ctx)));
	ASSERT(c->mlx = mlx_init());
	ASSERT(c->win = mlx_new_window(c->mlx, WIN_X, WIN_Y, WINDOW_NAME));
	c->buffs = NULL;
    ft_lstpush(&c->buffs, buffer_new(c, WIN_X, WIN_Y), sizeof(t_buff));
	return (c);
}
