/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/02/03 17:06:05 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIN_X 1024
# define WIN_Y 1024
# define FOV 40
# define CONE_ANGLE 30
# include "wrapper.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

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

/*
** intersect.c
*/
t_bool			intersect_sphere(t_ray ray, t_obj *obj, double *dis);
t_bool			intersect_plane(t_ray ray, t_obj *obj, double *dis);
t_bool			intersect_cylinder(t_ray ray, t_obj *obj, double *dis);
t_bool			intersect_cone(t_ray ray, t_obj *obj, double *dis);
void			quadratic_intersect(double *result,
					double a, double b, double c);

/*
** normal.c
*/
t_vec3			normal_sphere(t_obj *hit_obj, t_vec3 hp);
t_vec3			normal_plane(t_obj *hit_obj, t_vec3 hp);
t_vec3			normal_cylinder(t_obj *hit_obj, t_vec3 hp);
t_vec3			normal_cone(t_obj *cone, t_vec3 hp);

/*
** mlx.c
*/
int				close_window(t_rt *rt);
int				hook_keys(int key, t_rt *rt);
void			look_at(t_vec3 from, t_vec3 to, t_mat *cam);

/*
** parse.c & parse_help.c
*/
void			parse(char *file, t_rt *rt);
void			get_vec3(char *p1, char *p2, char *p3, t_vec3 *var);
void			parse_sphere(char **split, t_obj *obj);
void			parse_plane(char **split, t_obj *obj);
void			parse_cone_cylinder(char **split, t_obj *obj);

/*
** helper.c
*/
void			ft_err(char *s);
unsigned int	ft_htou(const char *str);
int				ft_iswhitespace(char c);
unsigned		color_mult(unsigned c, const float x);
#endif
