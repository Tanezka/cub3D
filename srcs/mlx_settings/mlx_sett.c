#include "../../library/mlx/mlx.h"
#include "../../inc/cub3d.h"

void	mlx_sett(t_cub *cube)
{
	t_data	test;
	test.img = mlx_new_image(cube->mlx, 1920, 1080);
	test.addr = mlx_get_data_addr(test.img, &test.bits_per_pixel, &test.line_length, &test.endian);
	cube->frame = &test;
	draw_rectangle(cube->frame, 960, 540, 15, 540);
	draw_rectangle(cube->frame, 960, 540, 15, -540); 
	//scale_and_cut(cube->text[0].img.img, 1920, 1080, (int[]){0,0}, (int[]){64,64});
	print_player(cube);
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