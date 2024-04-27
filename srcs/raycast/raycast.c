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
#include <stdio.h>

void	x_pos_y_pos(t_cub *cube, int angle, int index)
{

}

void	x_neg_y_pos(t_cub *cube, int angle, int index)
{

}

void	x_neg_y_neg(t_cub *cube, int angle, int index)
{

}

void	x_pos_y_neg(t_cub *cube, int angle, int index)
{

}

void	east_ray(t_cub *cube, int index)
{
	double		i;
	double		distance;
	double		value;
	double		x_pos;

	i = cube->pos.x;
	//printf("%f\n", i);
	while (cube->map[(int)cube->pos.y][(int)i] != '1')
	{
		i++;
	}
	distance = i - cube->pos.x;
	ft_printf("%d\n", index);
	value =  540 -((distance - 1) * 54); 
	draw_rectangle(cube->frame, index * 15, 540, 15, value);
	draw_rectangle(cube->frame, index * 15, 540, 15, -value);
}

void	ray_casting(t_cub *cube, int angle, int index)
{
	if (angle > 0 && angle < 90)
		x_pos_y_pos(cube, angle, index);
	else if (angle > 90 && angle < 180)
		x_neg_y_pos(cube, angle, index);
	else if (angle > 180 && angle < 270)
		x_neg_y_neg(cube, angle, index);
	else if (angle > 270 && angle < 360)
		x_pos_y_neg(cube, angle, index);
	else if (angle == 0)
		east_ray(cube, index);
	
}

/*
			typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

{
	t_data img;

	((int *)img.addr)[0];
}
*/
void	caster(t_cub *cube)
{
	int i;
	int	limit;
	int	index;

	index = 0;
	i = *cube->angle - 64;
	limit = *cube->angle + 65;
	while (i < limit)
	{
		ray_casting(cube, i, index);
		i++;
		index++;
	}
}

int	raycasting(t_cub *cube)
{
	int			x;
	int			y;
	int			z;
	void		*test;

	//ft_bzero(cube->img.addr, 1920 * 1080 * cube->img.bits_per_pixel / 8);
	caster(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->frame->img, 0, 0);
	//width = 15;
	//height = 15;
	//mlx_get_data_addr(cube->text[3].img.img, &x, &y, &z);
	//printf("%d, %d, %d\n", x, y, z);
	//mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	return (1);
}
