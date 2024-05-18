/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:31:28 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:31:31 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../library/mlx/mlx.h"

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
	cube->keys.w = false;
	cube->keys.a = false;
	cube->keys.s = false;
	cube->keys.d = false;
	cube->keys.left = false;
	cube->keys.right = false;
	cube->start_path = 0;
	return (init_cube2(cube));
}

int	init_cube2(t_cub *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		return (0);
	cube->no_path = NULL;
	cube->so_path = NULL;
	cube->we_path = NULL;
	cube->ea_path = NULL;
	cube->f_color[0] = -1;
	cube->f_color[1] = -1;
	cube->f_color[2] = -1;
	cube->c_color[0] = -1;
	cube->c_color[1] = -1;
	cube->c_color[2] = -1;
	return (1);
}
