#include "../inc/cub3d.h"
#include <stdio.h>
#include <fcntl.h>

int	error_message(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

int	init_cube(t_cub *cube)
{
	cube->map = ft_calloc(1, sizeof(char *));
	if (!cube->map)
		return (0);
	cube->map[0] = NULL;
	cube->map_height = 0;
	cube->map_width = 0;
	cube->pos.x = 0;
	cube->pos.y = 0;
	cube->keys.w = 0;
	cube->keys.a = 0;
	cube->keys.s = 0;
	cube->keys.d = 0;
	cube->keys.left = 0;
	cube->keys.right = 0;
	cube->start = 0;
	return (init_param(cube));
}

int init_param(t_cub *cube)
{
	cube->rend = ft_calloc(1, sizeof(t_render));
	if (!cube->rend)
		return (0);
	cube->no_path = NULL;
	cube->so_path = NULL;
	cube->we_path = NULL;
	cube->ea_path = NULL;
	cube->f_color[0] = 256;
	cube->f_color[1] = 256;
	cube->f_color[2] = 256;
	cube->c_color[0] = 256;
	cube->c_color[1] = 256;
	cube->c_color[2] = 256;
	return (1);
}