/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:10:43 by dhill             #+#    #+#             */
/*   Updated: 2018/01/23 17:00:35 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	camera(char **split, list)
{
	
}

void	sphere(char **split, list)
{
	
}

void	cylinder(char **split, list)
{
	
}

void	plane(char **split, list)
{
	
}

void	cone(char **split, list)
{
	
}

void	parse(lisssst)
{
	int		fd;
	int		chk;
	char	**split;
	char	*line;
	int		i;
	
	i = 0;

	(var->fd = open(str, O_RDONLY)) < 0 ? error("Opening file failed.") : 0;
	while ((chk = get_next_line(var->fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		!split ? error("Error: Data parsing failed.") : 0;
		while (split[i] != '\0')
		{
			if (ft_strcmp(split[0], "camera") == 0)
				camera(split, list);
			if (ft_strcmp(split[0], "sphere") == 0)
				sphere(split, list);
			if (ft_strcmp(split[0], "cylinder") == 0)
				cylinder(split, list);
			if (ft_strcmp(split[0], "plane") == 0)
				plane(split, list);
			if (ft_strcmp(split[0], "cone") == 0)
				cone(split, list);
		}

		ft_strdel(&line);
	}
}
