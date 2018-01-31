/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:55:55 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/31 13:44:53 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_vec3	normal_sphere(t_obj *hit_obj, t_vec3 hp)
{
	t_vec3 normal;

	normal = V3_MINUS_V3(hp, hit_obj->position);
	vec3_normalize(&normal);
	return (normal);
}

t_vec3	normal_plane(t_obj *hit_obj, t_vec3 hp)
{
	t_vec3 normal;

	(void)hp;
	normal = hit_obj->rotation;
	return (normal);
}
