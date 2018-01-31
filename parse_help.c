/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:43:58 by dhill             #+#    #+#             */
/*   Updated: 2018/01/31 11:51:41 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_vec3(char *p1, char *p2, char *p3, t_vec3 *var)
{
	var->x = ft_atof(p1);
	var->y = ft_atof(p2);
	var->z = ft_atof(p3);
}

void	parse_sphere(char **split, t_obj *obj)
{
	obj->type = t_sphere;
	obj->radius = ft_atof(split[4]);
	obj->color = ft_htou(split[5]);
}

void	parse_cone_plane(char **split, t_obj *obj)
{
	obj->type = ft_strequ(split[0], "cone") == 1 ? t_cone : t_plane;
	get_vec3(split[4], split[5], split[6], &obj->rotation);
	obj->color = ft_htou(split[7]);
}

void	parse_cylinder(char **split, t_obj *obj)
{
	obj->type = t_cylinder;
	get_vec3(split[4], split[5], split[6], &obj->rotation);
	obj->radius = ft_atof(split[7]);
	obj->color = ft_htou(split[8]);
}
