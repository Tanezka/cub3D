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
	cube->start_path = 0;
	return (init_param(cube));
}

int	init_param(t_cub *cube)
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

int	main(int ac, char **av)
{
	t_cub	cube;

	if (ac != 2)
		error_message("Invalid number of arguments");
	if (!init_cube(&cube))
		error_message("Failed to initialize cube");
	cube.mlx = mlx_init();
	if (!map_path_check(av[1]) || !parse_file(av[1], &cube))
	{
		cube_free(&cube);
		free(cube.mlx);
		exit(1);
	}
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
