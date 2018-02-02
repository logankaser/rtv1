/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:55:55 by lkaser            #+#    #+#             */
/*   Updated: 2018/02/01 21:31:41 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_bool	intersect_sphere(t_ray ray, t_obj *obj, double *dis)
{
	t_vec3	temp;
	double	d[2];
	double	disc;

	temp = V3_MINUS_V3(ray.o, obj->position);
	d[0] = V3_DOT(ray.d, temp);
	disc = d[0] * d[0] - V3_DOT(temp, temp) + obj->radius * obj->radius;
	if (disc < 1e-6)
		return (FALSE);
	disc = sqrt(disc);
	d[1] = -d[0] - disc;
	d[0] = -d[0] + disc;
	*dis = (d[0] < d[1]) ? d[0] : d[1];
	return (TRUE);
}

t_bool	intersect_plane(t_ray ray, t_obj *obj, double *dis)
{
	double	denom;
	t_vec3	hit;
	double	t;

	denom = V3_DOT(obj->rotation, ray.d);
	if (fabs(denom) > 1e-6)
	{
		hit = V3_MINUS_V3(obj->position, ray.o);
		t = V3_DOT(hit, obj->rotation) / denom;
		if (t >= 0)
		{
			*dis = t;
			return (TRUE);
		}
	}
	return (FALSE);
}

void	quadratic_intersect(double *result, double a, double b, double c)
{
	double disc;

	disc = b * b - 4 * a * c;
	if (disc < 0)
	{
		result[0] = INFINITY;
		result[1] = INFINITY;
		return ;
	}
	if (disc == 0)
	{
		result[0] = -b / (2 * a);
		result[1] = INFINITY;
		return ;
	}
	disc = sqrt(disc);
	result[0] = (-b + disc) / (2 * a);
	result[1] = (-b - disc) / (2 * a);
}
