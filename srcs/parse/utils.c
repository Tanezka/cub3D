#include "../../inc/cub3d.h"
#include "../../mlx/mlx.h"
#include <stdlib.h>

int	is_current_param(char *line, t_cub *cube, int *nbr)
{
	int		right;
	int		left;
	char	**split;

	split = ft_split(line, ' ');
	left = ft_strlen(split[0]);
	right = 0;
	if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO") \
	|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA"))
		right = check_direct_path(split, cube, nbr);
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
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

	i = 0;
	n = 0;
	if (split_len(split) != 2)
		return (0);
	colors = ft_split(split[1], ',');
	if (split_len(colors) != 3)
		n = -1;
	while (i < 3 && n != -1)
	{
		n = ft_atoi(colors[i]);
		if (n < 0 | n > 255)
			n = -1;
		else if (!ft_strcmp(split[0], "F"))
			cube->f_color[i] = n;
		else if (!ft_strcmp(split[0], "C"))
			cube->c_color[i] = n;
		i++;
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
	img = get_image(cube, path);
	if (!img.img)
		return (0);
	if (!ft_strcmp(split[0], "NO") && !cube->no_path)
		cube->no_path = path;
	else if (!ft_strcmp(split[0], "SO") && !cube->so_path)
		cube->so_path = path;
	else if (!ft_strcmp(split[0], "WE") && !cube->we_path)
		cube->we_path = path;
	else if (!ft_strcmp(split[0], "EA") && !cube->ea_path)
		cube->ea_path = path;
	else
		return (0);
	mlx_destroy_image(cube->mlx, img.img);
	*nbr += 1;
	return (1);
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
	return (img);
}

int	map_path_check(char *map_path)
{
	if (ft_strcmp(map_path + ft_strlen(map_path) - 4, ".cub") != 0)
	{
		error_message("Wrong file format");
		return (0);
	}
	return (1);
}
