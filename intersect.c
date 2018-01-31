/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:55:55 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/30 20:19:00 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_bool	intersect_sphere(t_ray ray, t_obj *obj, double *dis)
{
	double b;
	double disc;
	t_vec3 oc;
	double t0;
	double t1;

	oc = V3_MINUS_V3(ray.o, obj->position);
	b = 2 * V3_DOT(oc, ray.d);
	disc = b * b - 4 * (V3_DOT(oc, oc) - obj->radius * obj->radius);
	if (disc < 0.00001)
		return (FALSE);
	disc = sqrt(disc);
	t0 = -b - disc;
	t1 = -b + disc;
	*dis = (t0 < t1) ? t0 : t1;
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
