/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:56:40 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:56:42 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../library/mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	cube_free(t_cub *cube)
{
	split_free(cube->map);
	free(cube->ea_path);
	free(cube->no_path);
	free(cube->we_path);
	free(cube->so_path);
}

void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	all_free(t_cub *var)
{
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->img.img);
	mlx_destroy_image(var->mlx, var->text[0].img.img);
	mlx_destroy_image(var->mlx, var->text[1].img.img);
	mlx_destroy_image(var->mlx, var->text[2].img.img);
	mlx_destroy_image(var->mlx, var->text[3].img.img);
	cube_free(var);
}
