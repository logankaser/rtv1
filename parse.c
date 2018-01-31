/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:14:37 by dhill             #+#    #+#             */
/*   Updated: 2018/01/31 11:42:34 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASSERT_FAIL ft_puterror("Malloc failed!\n");exit(1);
#include "rtv1.h"

void	ft_err(char *s)
{
	ft_putendl(s);
	exit(1);
}

void	parse_camera_struct(char **split, t_rt *rt)
{
	t_vec3	from;
	t_vec3	to;

	get_vec3(split[1], split[2], split[3], &from);
	get_vec3(split[4], split[5], split[6], &to);
	look_at(from, to, &rt->cam);
}

void	parse_light_list(char **split, t_rt *rt)
{
	t_light *light;

	ASSERT((light = malloc(sizeof(t_light))));
	get_vec3(split[1], split[2], split[3], &light->position);
	light->intensity = ft_atof(split[4]);
	ft_lstpush(&rt->lights, light, sizeof(light));
}

void	parse_object_list(char **split, t_rt *rt)
{
	t_obj   *obj;

	ASSERT((obj = malloc(sizeof(t_obj))));
	get_vec3(split[1], split[2], split[3], &obj->position);
	if (ft_strequ(split[0], "sphere") == 1)
		parse_sphere(split, obj);
	else if (ft_strequ(split[0], "cone") == 1 || ft_strequ(split[0], "plane") == 1)
		parse_cone_plane(split, obj);
	else if (ft_strequ(split[0], "cylinder") == 1)
		parse_cylinder(split, obj);
	ft_lstpush(&rt->objs, obj, sizeof(obj));
}

void	parse(char	*file, t_rt *rt)
{
	int		fd;
	char	**split;
	char	*line;

	(fd = open(file, O_RDONLY)) < 0 ? ft_err("Opening file failed.") : 0;
	rt->objs = NULL;
	rt->lights = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		!split ? ft_err("Error: Data parsing failed.") : 0;
		if (ft_strequ(split[0], "camera") == 1)
			parse_camera_struct(split, rt);
		else if (ft_strequ(split[0], "light") == 1)
			parse_light_list(split, rt);
		else
			parse_object_list(split, rt);
		ft_strdel(&line);
	}
}
