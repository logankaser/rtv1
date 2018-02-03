/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:24:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/02/02 18:53:59 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	quad_a(t_vec3 dir, t_obj *cone)
{
	double dot;
	double cos_sq;

	dot = V3_DOT(dir, cone->rotation);
	cos_sq = cos(cone->radius);
	return (dot * dot - cos_sq * cos_sq);
}

static double	quad_b(t_vec3 dir, t_obj *cone, t_vec3 diff)
{
	double dot1;
	double dot2;
	double dot3;
	double cos_sq;

	dot1 = V3_DOT(dir, cone->rotation);
	dot2 = V3_DOT(diff, cone->rotation);
	dot3 = V3_DOT(dir, diff);
	cos_sq = cos(cone->radius);
	cos_sq *= cos_sq;
	return (2 * (dot1 * dot2 - dot3 * cos_sq));
}

static double	quad_c(t_obj *cone, t_vec3 diff)
{
	double dot1;
	double dot2;
	double cos_sq;

	dot1 = V3_DOT(diff, cone->rotation);
	dot2 = V3_DOT(diff, diff);
	cos_sq = cos(cone->radius);
	cos_sq *= cos_sq;
	return (dot1 * dot1 - dot2 * cos_sq);
}

t_bool			intersect_cone(t_ray ray, t_obj *cone, double *dis)
{
	t_vec3 diff;
	double zeros[2];
	double temp;

	diff = V3_MINUS_V3(ray.o, cone->position);
	quadratic_intersect(zeros,
		quad_a(ray.d, cone),
		quad_b(ray.d, cone, diff),
		quad_c(cone, diff));
	temp = (zeros[0] < zeros[1]) ? zeros[0] : zeros[1];
	if (temp > 1e-6)
	{
		*dis = temp;
		return (TRUE);
	}
	else
		return (FALSE);
}
