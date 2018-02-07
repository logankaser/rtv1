/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:55:55 by lkaser            #+#    #+#             */
/*   Updated: 2018/02/06 20:31:46 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_vec3	normal_sphere(t_obj *sphere, t_vec3 hp)
{
	t_vec3 normal;

	normal = V3_MINUS_V3(hp, sphere->position);
	vec3_normalize(&normal);
	return (normal);
}

t_vec3	normal_plane(t_obj *plane, t_vec3 hp)
{
	(void)hp;
	return (plane->rotation);
}

t_vec3	normal_cylinder(t_obj *cyl, t_vec3 hp)
{
	t_vec3	normal;
	double	dis;

	normal = V3_MINUS_V3(hp, cyl->position);
	dis = V3_DOT(normal, cyl->rotation);
	normal.x = cyl->position.x + cyl->rotation.x * dis;
	normal.y = cyl->position.y + cyl->rotation.y * dis;
	normal.z = cyl->position.z + cyl->rotation.z * dis;
	normal = V3_MINUS_V3(hp, normal);
	vec3_normalize(&normal);
	return (normal);
}

t_vec3	normal_cone(t_obj *cone, t_vec3 hp)
{
	double	side_len;
	t_vec3	normal;

	normal = V3_MINUS_V3(hp, cone->position);
	side_len = sqrt(V3_DOT(normal, normal));
	side_len /= cos(cone->radius);
	if (V3_DOT(normal, cone->rotation) < 0)
		side_len = -side_len;
	normal.x = cone->position.x + side_len * cone->rotation.x;
	normal.y = cone->position.y + side_len * cone->rotation.y;
	normal.z = cone->position.z + side_len * cone->rotation.z;
	normal = V3_MINUS_V3(hp, normal);
	vec3_normalize(&normal);
	return (normal);
}
