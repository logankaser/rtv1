/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:14:37 by dhill             #+#    #+#             */
/*   Updated: 2018/01/24 00:01:20 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	get_position(char *p1, char *p2, char *p3)
{
	//will always be first 3 doubles;
}

t_vec3	get_rotation(char *r1, char *r2, char *r3)
{
	//unsure of this, the direction maybe
}

double	get_radius(char *radius)
{
	//just a quick atof of whatever 'string' the radius is
}

unsigned	get_color(char *color)
{
	//change 0xFFFFFF str to an usnigned int
	return (ft_htou(color));
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
