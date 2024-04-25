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
#include "../../mlx/mlx.h"
#include <stdio.h>

void	x_pos_y_pos(t_cub *cube, int angle);
void	x_neg_y_pos(t_cub *cube, int angle);
void	x_neg_y_neg(t_cub *cube, int angle);
void	x_pos_y_neg(t_cub *cube, int angle);

void	ray_casting(t_cub *cube, int angle)
{
	if (angle > 0 && angle < 90)
		x_pos_y_pos(cube, angle);
	else if (angle > 90 && angle < 180)
		x_neg_y_pos(cube, angle);
	else if (angle > 90 && angle < 180)
		x_neg_y_neg(cubei angle);
	else if (angle > 90 && angle < 180)
	

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

	i = *cube->angle - 65;
	limit = *cube->angle + 65;
	while (i < limit)
	{
		ray_casting(cube, i);
		i++;
	}
}

int	render_next_frame(t_cub *cube)
{
	int			x;
	int			y;
	int			z;
	t_render	*rend;
	void		*test;

	rend = cube->rend;
	//ft_bzero(cube->img.addr, 1920 * 1080 * cube->img.bits_per_pixel / 8);
	
	mlx_put_image_to_window(cube->mlx, cube->win, cube->frame->img, 0, 0);
	//width = 15;
	//height = 15;
	//mlx_get_data_addr(cube->text[3].img.img, &x, &y, &z);
	//printf("%d, %d, %d\n", x, y, z);
	//render_walls(cube);
	//mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	return (1);
}
