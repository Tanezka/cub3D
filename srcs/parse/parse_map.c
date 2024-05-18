/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:53:11 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:53:12 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

int	resize_map(t_cub *cube)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (cube->map[++i])
	{
		if (ft_strlen(cube->map[i]) == cube->map_width)
			continue ;
		tmp = ft_calloc(cube->map_width + 1, sizeof(char));
		if (!tmp)
			return (0);
		j = -1;
		while (cube->map[i][++j])
			tmp[j] = cube->map[i][j];
		while (j < cube->map_width)
			tmp[j++] = ' ';
		tmp[j] = 0;
		free(cube->map[i]);
		cube->map[i] = tmp;
	}
	return (1);
}

int	parse_map(char *line, t_cub *cube)
{
	int		i;
	int		width;
	char	**new_map;

	if (!check_current_map_line(line, cube))
		return (0);
	i = -1;
	width = ft_strlen(line);
	cube->map_height++;
	if (width > cube->map_width)
		cube->map_width = width;
	new_map = ft_calloc(cube->map_height + 1, sizeof(char *));
	if (!new_map)
		return (0);
	while (cube->map[++i])
		new_map[i] = cube->map[i];
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(cube->map);
	cube->map = new_map;
	return (1);
}

int	check_current_map_line(char *line, t_cub *cube)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr("10 NSEW\t", line[i]))
		{
			ft_printf("Error\nInvalid %c character in map\n", line[i]);
			return (0);
		}
		else if (ft_strchr("NSEW", line[i]) && cube->start_path != 0)
		{
			ft_printf("Error\nMultiple starting points\n");
			return (0);
		}
		else if (ft_strchr("NSEW", line[i]) && cube->start_path == 0)
		{
			cube->start_path = line[i];
			cube->pos.x = (double)i + 0.5f;
			cube->pos.y = (double)cube->map_height + 0.5f;
			wall_direction(cube);
		}
	}
	return (1);
}
