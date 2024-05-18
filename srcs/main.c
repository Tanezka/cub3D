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

#include "../library/mlx/mlx.h"
#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cube;

	if (ac != 2)
		error_message("Missing or invalid argument \nUse: ./cub3D map.cub");
	if (!init_cube(&cube))
		error_message("Failed to initialize cube");
	if (!map_path_check(av[1]) || !parse_file(av[1], &cube))
		clean(&cube);
	mlx_sett(&cube);
	init_textures(&cube);
	mlx_loop_hook(cube.mlx, raycasting, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
