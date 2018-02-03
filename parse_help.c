/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:43:58 by dhill             #+#    #+#             */
/*   Updated: 2018/02/02 17:43:37 by dhill            ###   ########.fr       */
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
	if (!split[5] || (split[5] && split[6]))
		ft_err("Improper sphere format.");
	obj->type = t_sphere;
	obj->radius = ft_atof(split[4]);
	obj->color = ft_htou(split[5]);
}

void	parse_plane(char **split, t_obj *obj)
{
	if (!split[7] || (split[7] && split[8]))
		ft_err("Improper plane format.");
	obj->type = t_plane;
	get_vec3(split[4], split[5], split[6], &obj->rotation);
	vec3_normalize(&obj->rotation);
	obj->color = ft_htou(split[7]);
}

void	parse_cone_cylinder(char **split, t_obj *obj)
{
	if (!split[8] || (split[8] && split[9]))
		ft_err("Improper cone or cylinder format.");
	if (ft_strequ(split[0]) == "cone")
	{
		obj->type = t_cone;
		obj->radius = ft_atof(split[7]) * M_PI / 180;
	}
	else
	{
		obj->type = t_cylinder;
		obj->radius = ft_atof(split[7]);
	}
	get_vec3(split[4], split[5], split[6], &obj->rotation);
	vec3_normalize(&obj->rotation);
	obj->color = ft_htou(split[8]);
}
