/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/22 16:08:39 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef	enum		e_type
{
	t_plane = 1,
	t_sphere,
	t_cylinder,
	t_cone
}					t_type;

typedef struct		s_map
{
	t_ctx			*c;
	int				width;
	t_list			*data;
}					t_map;

typedef	struct		s_object
{
	t_vec3			position;
	double			radius;
	unsigned		color;
}					t_obj;

typedef	struct		s_light
{
	unsigned		color;
	double			intensity;
}


#endif
