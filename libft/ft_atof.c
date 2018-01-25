/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:02:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/25 15:26:41 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	t_bool		neg;
	t_bool		point;
	unsigned	fac;
	double		out;

	out = 0;
	fac = 1;
	point = FALSE;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if ((neg = *str == '-') || *str == '+')
		++str;
	while ((*str >= '0' && *str <= '9') || (*str == '.' && !point))
	{
		if (*str == '.')
		{
			point = TRUE;
			++str;
			continue ;
		}
		if (point)
			fac *= 10;
		out = out * 10.0f + (double)(*str++ - '0');
	}
	return ((neg ? -out : out) / fac);
}
