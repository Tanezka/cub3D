/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:53:45 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:53:46 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	parse_line(char *line, t_cub *cube, int *nbr)
{
	int	value;

	if (ft_strlen(line) <= 1)
	{
		value = *nbr != -1;
		if (value != 0)
			free(line);
	}
	else if (*nbr < 6 && *nbr != -1)
		value = is_current_param(line, cube, nbr);
	else
	{
		*nbr = -1;
		if (!check_path_color(cube))
			return (0);
		value = parse_map(line, cube);
	}
	if (value == 0)
		error_message("Invalid line in file");
	return (value);
}

int	parse_file(char *filename, t_cub *cube)
{
	int		fd;
	int		nbr;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	((line = line_reading(fd)) && (nbr = 0));
	if (!line)
		return (error_message("Empty file"));
	while (line)
	{
		if (!parse_line(line, cube, &nbr))
			return (free(line), 0);
		line = line_reading(fd);
	}
	close(fd);
	free(line);
	if (!cube->start_path)
		return (error_message("Missing path in file {N, S, E, W}"));
	resize_map(cube);
	check_closed_map(cube);
	return (1);
}

int	check_path_color(t_cub *cube)
{
	int	i;

	i = 0;
	if (cube->no_path == NULL || cube->so_path == NULL || \
	cube->we_path == NULL || cube->ea_path == NULL)
	{
		ft_printf("Error\nMissing path in file\n");
		return (0);
	}
	while (i < 3)
	{
		if (cube->f_color[i] == -1 || cube->c_color[i] == -1)
		{
			ft_printf("Error\nMissing color in file\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_map(char *line, t_cub *cube)
{
	int		i;
	int		width;
	char	**new_map;

	i = -1;
	if (!check_current_map_line(line, cube))
		return (0);
	width = ft_strlen(line);
	cube->map_height++;
	if (width > cube->map_width)
		cube->map_width = width;
	new_map = ft_calloc(cube->map_height + 1, sizeof(char *));
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
	while (line[++i] != '\n' && line[i] != '\0')
	{
		if (!ft_strchr("10 NSEW", line[i]))
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
			cube->pos.x = (double)i;
			cube->pos.y = (double)cube->map_height;
		}
	}
	return (1);
}
