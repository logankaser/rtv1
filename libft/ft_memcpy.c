/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:45:43 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/16 14:51:00 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const uint64_t	*sr;
	uint64_t		*de;

	d = dest;
	while (n && n % 8)
	{
		--n;
		d[n] = ((unsigned char*)src)[n];
	}
	n /= 8;
	de = dest;
	sr = src;
	while (n)
	{
		--n;
		de[n] = sr[n];
	}
	return (dest);
}
