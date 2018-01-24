/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/23 20:59:31 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1920
# define WIN_Y 1080
# define FOV 30
# include "wrapper.h"

typedef	enum	e_type
{
	t_plane = 1,
	t_sphere,
	t_cylinder,
	t_cone
}				t_type;

typedef	struct	s_object
{
	t_vec3		position;
	t_vec3		rotation;
	t_type		type;
	double		radius;
	unsigned	color;
}				t_obj;

typedef	struct	s_light
{
	unsigned	color;
	double		intensity;
}				t_light;

#endif
