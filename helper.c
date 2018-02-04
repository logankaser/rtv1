/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:51:09 by dhill             #+#    #+#             */
/*   Updated: 2018/02/03 16:52:34 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v'
			|| c == '\f')
		return (1);
	return (0);
}

unsigned	ft_htou(const char *str)
{
	unsigned int	i;
	unsigned int	out;

	i = 0;
	out = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
	{
		i += 2;
		while (str[i] && ((str[i] >= '0' && str[i] <= '9') ||
					(str[i] >= 'A' && str[i] <= 'F')))
		{
			if (str[i] >= 'A')
				out = out * 16 + str[i] - 'A' + 10;
			else
				out = out * 16 + str[i] - '0';
			i++;
		}
		return (out);
	}
	else
		return (ft_atoi(str));
}

unsigned	color_mult(unsigned c, const float x)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	b = (c & 0xFF) * x;
	g = (c >> 8 & 0xFF) * x;
	r = (c >> 16 & 0xFF) * x;
	return (RGB(r, g, b));
}
