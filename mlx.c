/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:44:27 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/23 20:51:10 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Error initializing libmlx!");exit(1)
#include "RTv1.h"
#include "wrapper.h"

int			hook_keys(int key, t_ctx *c)
{
	if (key == 53)
	{
		mlx_destroy_window(c->mlx, c->win);
		free(c->mlx);
		free(c);
		exit(0);
	}
	return (0);
}

t_ctx		*initalize(void)
{
	t_ctx	*c;

	ASSERT(c = malloc(sizeof(t_ctx)));
	ASSERT(c->mlx = mlx_init());
	ASSERT(c->win = mlx_new_window(c->mlx, WIN_X, WIN_Y, WINDOW_NAME));
	return (c);
}
