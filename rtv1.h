/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/30 22:56:33 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

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
	t_vec3		position;
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

t_bool			intersect_sphere(t_ray *ray, t_obj *obj, double *dis);
int				hook_keys(int key, t_rt *rt);
void			look_at(t_vec3 from, t_vec3 to, t_mat *cam);

/*
** parse_help.c
*/
void	get_vec3(char *p1, char *p2, char *p3, t_vec3 *var);
void	parse_sphere(char **split, t_obj *obj);
void	parse_cone_plane(char **split, t_obj *obj);
void	parse_cylinder(char **split, t_obj *obj);
#endif
