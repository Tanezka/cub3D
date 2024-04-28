/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:54:06 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:54:08 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../library/mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	is_current_param(char *line, t_cub *cube, int *nbr)
{
	int		right;
	char	**split;
	char	*one_var;
	char	*uppercase_var;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	one_var = split[0];
	uppercase_var = ft_str_toupper(one_var);
	if (!uppercase_var)
		return (error_message("Failed to convert to uppercase"));
	right = 0;
	if (!ft_strcmp(uppercase_var, "NO") || !ft_strcmp(uppercase_var, "SO") \
	|| !ft_strcmp(uppercase_var, "WE") || !ft_strcmp(uppercase_var, "EA"))
		right = check_direct_path(split, cube, nbr);
	else if (!ft_strcmp(uppercase_var, "F") || !ft_strcmp(uppercase_var, "C"))
		right = check_color(split, cube, nbr);
	if (right != 0)
		free(line);
	split_free(split);
	return (right);
}

int	check_color(char **split, t_cub *cube, int *nbr)
{
	char	**colors;
	int		i;
	int		n;

	((i = -1) && (n = 0));
	if (split_len(split) != 2)
		return (0);
	colors = ft_split(split[1], ',');
	if (!colors)
		return (0);
	if (split_len(colors) != 3)
		n = -1;
	while (++i < 3 && n != -1)
	{
		n = ft_atoi(colors[i]);
		if (n < 0 | n > 255)
			n = -1;
		else if (!ft_strcmp(ft_str_toupper(split[0]), "F"))
			cube->f_color[i] = n;
		else if (!ft_strcmp(ft_str_toupper(split[0]), "C"))
			cube->c_color[i] = n;
	}
	split_free(colors);
	*nbr += 1;
	return (n != -1);
}

int	check_direct_path(char **split, t_cub *cube, int *nbr)
{
	char	*path;
	t_data	img;

	if (split_len(split) != 2)
		return (0);
	path = ft_strdup(split[1]);
	if (!path)
		return (0);
	path[ft_strlen(path) - 1] = 0;
	img = get_image(cube, path);
	if (!img.img)
		return (0);
	if (!ft_strcmp(ft_str_toupper(split[0]), "NO") && !cube->no_path)
		cube->no_path = path;
	else if (!ft_strcmp(ft_str_toupper(split[0]), "SO") && !cube->so_path)
		cube->so_path = path;
	else if (!ft_strcmp(ft_str_toupper(split[0]), "WE") && !cube->we_path)
		cube->we_path = path;
	else if (!ft_strcmp(ft_str_toupper(split[0]), "EA") && !cube->ea_path)
		cube->ea_path = path;
	else
		return (0);
	mlx_destroy_image(cube->mlx, img.img);
	return ((*nbr += 1), 1);
}

t_data	get_image(t_cub *cube, char *path)
{
	t_data	img;
	int		width;
	int		height;

	img.img = mlx_xpm_file_to_image(cube->mlx, path, &width, &height);
	if (!img.img)
	{
		free(path);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	if (img.addr == NULL)
	{
		mlx_destroy_image(cube->mlx, img.img);
		free(path);
	}
	return (img);
}
