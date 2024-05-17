#include "../../library/mlx/mlx.h"
#include "../../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	mlx_sett(t_cub *cube)
{
	int		(*fnc1)();

	cube->dir_y = ft_calloc(1, sizeof(double));
	cube->dir_x = ft_calloc(1, sizeof(double));
	cube->plane_x = ft_calloc(1, sizeof(double));
	cube->plane_y = ft_calloc(1, sizeof(double));
	*cube->dir_x = -1;
	*cube->dir_y = 0;
	*cube->plane_x = 0.0f;
	*cube->plane_y = 0.66f;
	cube->win = mlx_new_window(cube->mlx, 1920, 1080, "cub3D");
	mlx_hook(cube->win, 2, 1L << 0, key_press, cube);
	mlx_hook(cube->win, 3, 1L << 1, key_release, cube);
	mlx_hook(cube->win, 17, 1L << 17, close_win, cube);
	fnc1 = change_angle;
	cube->img.img = mlx_new_image(cube->mlx, 1920, 1080);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bits_per_pixel,
			&cube->img.line_length, &cube->img.endian);
	if (cube->img.addr == NULL)
		error_message("Failed to create image");
	cube->frame = &cube->img;
}
