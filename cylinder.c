/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:16:57 by lkaser            #+#    #+#             */
/*   Updated: 2018/02/02 15:01:27 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	quad_a(t_vec3 dir, t_obj *cyl)
{
	t_vec3 temp;
	double dot;

	dot = V3_DOT(dir, cyl->rotation);
	temp.x = dot * cyl->rotation.x;
	temp.y = dot * cyl->rotation.y;
	temp.z = dot * cyl->rotation.z;
	temp = V3_MINUS_V3(dir, temp);
	return (V3_DOT(temp, temp));
}

static double	quad_b(t_vec3 diff, t_vec3 dir, t_obj *cyl)
{
	t_vec3 temp1;
	t_vec3 temp2;
	double dot;

	dot = V3_DOT(diff, cyl->rotation);
	temp1.x = dot * cyl->rotation.x;
	temp1.y = dot * cyl->rotation.y;
	temp1.z = dot * cyl->rotation.z;
	temp1 = V3_MINUS_V3(diff, temp1);
	dot = V3_DOT(dir, cyl->rotation);
	temp2.x = dot * cyl->rotation.x;
	temp2.y = dot * cyl->rotation.y;
	temp2.z = dot * cyl->rotation.z;
	temp2 = V3_MINUS_V3(dir, temp2);
	return (2 * V3_DOT(temp2, temp1));
}

static double	quad_c(t_vec3 diff, t_obj *cyl)
{
	t_vec3 temp;
	double dot;

	dot = V3_DOT(diff, cyl->rotation);
	temp.x = dot * cyl->rotation.x;
	temp.y = dot * cyl->rotation.y;
	temp.z = dot * cyl->rotation.z;
	temp = V3_MINUS_V3(diff, temp);
	return (V3_DOT(temp, temp) - cyl->radius * cyl->radius);
}

t_bool			intersect_cylinder(t_ray ray, t_obj *cyl, double *dis)
{
	t_vec3	diff;
	double	zeros[2];
	double	temp;

	diff = V3_MINUS_V3(ray.o, cyl->position);
	quadratic_intersect(zeros,
		quad_a(ray.d, cyl),
		quad_b(diff, ray.d, cyl),
		quad_c(diff, cyl));
	temp = (zeros[0] < zeros[1]) ? zeros[0] : zeros[1];
	if (temp > 1e-6)
	{
		*dis = temp;
		return (TRUE);
	}
	else
		return (FALSE);
}
