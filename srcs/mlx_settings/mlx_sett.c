#include "../../library/mlx/mlx.h"
#include "../../inc/cub3d.h"

void	mlx_sett(t_cub *cube)
{
	cube->win = mlx_new_window(cube->mlx, 1920, 1080, "cub3D");
	mlx_hook(cube->win, 2, 1L << 0, key_press, cube);
	mlx_hook(cube->win, 3, 1L << 1, key_release, cube);
	mlx_hook(cube->win, 17, 1L << 17, close_win, cube);
	cube->img.img = mlx_new_image(cube->mlx, 1920, 1080);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bits_per_pixel,
			&cube->img.line_length, &cube->img.endian);
	if (cube->img.addr == NULL)
		error_message("Failed to create image");
}
