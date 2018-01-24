/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:10:43 by dhill             #+#    #+#             */
/*   Updated: 2018/01/23 22:56:01 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

//if none of these have to be any different than the name,
//just make one function and add the name in the assignation to it
void	camera(char **split, t_obj *obj)
{
	obj->type = t_camera;
	obj->position = get_position(split[1], split[2], split[3]);
	obj->rotation = get_rotation(split[4], split[5], split[6]);
}

void	sphere(char **split, list)
{
	obj->type = t_sphere;
	obj->position = get_position(split[1], split[2], split[3]);
	obj->rotation = get_rotation(split[4], split[5], split[6]);
	obj->color = get_color(split[8]);
}

void	cylinder(char **split, list)
{
	obj->type = t_cylinder;
	obj->position = get_position(split[1], split[2], split[3]);
	obj->rotation = get_rotation(split[4], split[5], split[6]);
	obj->color = get_color(split[8]);
}

void	plane(char **split, list)
{
	obj->type = t_plane;
	obj->position = get_position(split[1], split[2], split[3]);
	obj->rotation = get_rotation(split[4], split[5], split[6]);
	obj->color = get_color(split[8]);
}

void	cone(char **split, list)
{
	obj->type = t_cone;
	obj->position = get_position(split[1], split[2], split[3]);
	obj->rotation = get_rotation(split[4], split[5], split[6]);
	obj->color = get_color(split[8]);
}
