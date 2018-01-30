/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/29 18:29:31 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1024
# define WIN_Y 1024
# define FOV 40
# include "wrapper.h"

typedef struct	s_ray
{
	t_vec3		o;
	t_vec3		d;
}				t_ray;

typedef	enum	e_type
{
	t_sphere = 1,
	t_plane,
	t_cylinder,
	t_cone
}				t_type;

typedef	struct	s_object
{
	t_type		type;
	t_vec3		position;
	t_vec3		rotation;
	double		radius;
	unsigned	color;
}				t_obj;

typedef	struct	s_light
{
	unsigned	color;
	double		intensity;
}				t_light;

typedef	struct	s_camera
{
	t_vec3		pos;
	t_vec3		dir;
}				t_camera;

typedef	struct	s_rt
{
	t_ctx		*c;
	t_list		*objs;
	t_list		*lights;
	double		scale;
	double		aspect;
	t_mat		cam;
}				t_rt;

void			trace_sphere(t_ray *ray, t_obj *obj, double *dis);

#endif
