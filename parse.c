/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:14:37 by dhill             #+#    #+#             */
/*   Updated: 2018/01/28 16:44:47 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_vec3(char *p1, char *p2, char *p3, t_vec3 var)
{
	var->x = ft_atof(p1);
	var->y = ft_atof(p2);
	var->z = ft_atof(p3);
}

void	parse_placement(char **split, list)
{
	obj->position = get_vec3(split[1], split[2], split[3]);
	obj->rotation = get_vec3(split[4], split[5], split[6]);
}

void	parse_detail(char **split, object)
{
	obj->radius = ft_atof(split[7]);
	obj->color = ft_htou(split[8]);
}

void	parse_all(char **split, object)
{
	int i;

	i = 0;	
	while (split[i] != '\0')
	{
		if (ft_strcmp(split[0], "camera") == 0)
			parse_placement(split, list obj);
		if (ft_strcmp(split[0], "sphere") == 0)
		{
			obj->type = t_sphere;
			parse_placement(split, list obj);
			parse_detail(split, obj);
		}
		if (ft_strcmp(split[0], "cylinder") == 0)
		{
			obj->type = t_cylinder;
			parse_placement(split, list obj);
			parse_detail(split, obj);
		}
		if (ft_strcmp(split[0], "cone") == 0)
		{
			obj->type = t_cone;
			parse_placement(split, list obj);
			parse_detail(split, obj);
		}
		if (ft_strcmp(split[0], "plane") == 0)
		{
			obj->type = t_cone;
			parse_placement(split, list obj);
			obj->color = ft_htou(split[7]);
		}
		i++;
	}
}

void	parse(t_list objs)
{
	int		fd;
	int		chk;
	char	**split;
	char	*line;

	(var->fd = open(str, O_RDONLY)) < 0 ? error("Opening file failed.") : 0;
	while ((chk = get_next_line(var->fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		!split ? error("Error: Data parsing failed.") : 0;
		parse_all(split, obj);
		ft_strdel(&line);
	}
}
