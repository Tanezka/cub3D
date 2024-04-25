/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:57:38 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:57:40 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	scale_and_cut(void *text, int width, int height, int start_pos[2], int area[2])
{
	int	scale_y;
}

void	handle_neg_scale(int *x, int *width, int *y, int *height)
{
	if (*height < 0)
	{
		*y += *height;
		*height *= -1;
	}
	if (*width < 0)
	{
		*x += *width;
		*width *= -1;
	}
}

void	draw_rectangle (void *frame, int x, int y, int width, int height)
{
	int	limit_x;
	int	limit_y;

	handle_neg_scale(&x, &width, &y, &height);
	limit_x = x + width;
	limit_y = y + height;
	while(y < limit_y)
	{
		while(x < limit_x)
		{
			pixel(frame, x, y, 0x0000FF00);
			x++;
		}
		x = limit_x - width;
		y++;
	}
}

int	main(int ac, char **av)
{
	t_cub	cube;
	t_data	test;

	if (ac != 2)
		error_message("Invalid argument\nUse ./cub3D map.cub");
	if (!init_cube(&cube))
		error_message("Failed to initialize cube");
	cube.mlx = mlx_init();
	if (!map_path_check(av[1]) || !parse_file(av[1], &cube))
	{
		/*cube_free(&cube);
		free(cube.mlx);
		exit(1);*/
	}
	test.img = mlx_new_image(cube.mlx, 1920, 1080);
	test.addr = mlx_get_data_addr(test.img, &test.bits_per_pixel, &test.line_length, &test.endian);
	cube.frame = &test;
	//draw_rectangle(cube.frame, 960, 540, 15, 540);
	//draw_rectangle(cube.frame, 960, 540, 15, -540);
	//scale_and_cut(cube.text[0].img.img, 1920, 1080, (int[]){0,0}, (int[]){64,64});
	print_player(&cube);
	cube.win = mlx_new_window(cube.mlx, 1920, 1080, "cub3D");
	mlx_hook(cube.win, 2, 1L << 0, key_press, &cube);
	mlx_hook(cube.win, 3, 1L << 1, key_release, &cube);
	mlx_hook(cube.win, 17, 1L << 17, close_win, &cube);
	cube.img.img = mlx_new_image(cube.mlx, 1920, 1080);
	cube.img.addr = mlx_get_data_addr(cube.img.img, &cube.img.bits_per_pixel,
			&cube.img.line_length, &cube.img.endian);
	init_textures(&cube);
	mlx_loop_hook(cube.mlx, render_next_frame, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
