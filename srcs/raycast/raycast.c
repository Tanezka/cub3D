/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:54:40 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:54:41 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../library/mlx/mlx.h"
#include <math.h>
#include <stdio.h>

void	fill_black(t_cub *cube)
{
	int	i;
	int	y;

	y = 0;
	while (y < S_HEIGHT)
	{
		i = 0;
		while (i < S_WIDTH)
		{
			if (y > S_HEIGHT / 2)
				pixel(cube->frame, i, y, cube->f_color_code);
			else
				pixel(cube->frame, i, y, cube->c_color_code);
			i++;
		}
		y++;
	}
}

void	draw_line_test(t_cub *cube, t_ray *ray)
{
	int		i;
	int		color;
	t_text	text;

	ray->text_y = (int)ray->text_pos;
	ray->text_y += ray->step;
	color = 0;
	if (ray->side == 1)
	{
		if (ray->dir_y > 0)
			text = cube->text[0];
		else
			text = cube->text[1];
	}
	else
	{
		if (ray->dir_x > 0)
			text = cube->text[3];
		else
			text = cube->text[2];
	}
	i = ray->draw_start;
	draw_line_test2(cube, ray, text, i);
}

void	fill_ray_array(t_cub *cube)
{
	int	index;

	index = -1;
	while (++index < S_WIDTH)
		cube->ray_array[index] = ray_initiator(cube, index);
}

int	raycasting(t_cub *cube)
{
	change_angle(cube);
	fill_black(cube);
	fill_ray_array(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->frame->img, 0, 0);
	return (1);
}
