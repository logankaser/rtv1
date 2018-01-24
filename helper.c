/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:59:02 by dhill             #+#    #+#             */
/*   Updated: 2018/01/23 23:13:27 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned int    ft_htou(const char *str)
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
