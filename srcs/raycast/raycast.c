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
	while(y < 1080)
	{
		i = 0;
		while(i < 1920)
		{
            if (y > 540)
			    pixel(cube->frame, i, y, 14753280);//ceiling renk değişir
            else
			    pixel(cube->frame, i, y, 0xFFFFF0);//floor
			i++;
		}
		y++;
	}
}

void	calculate_textures(t_cub *cube, t_ray *ray , int side)
{
	double	wall_hit;
	
	if (side == 0)
		wall_hit = cube->pos.y + *ray->perp_wall_dist * *ray->dir_y;
	else
		wall_hit = cube->pos.x + *ray->perp_wall_dist * *ray->dir_x;
}

void	draw_line_test(t_cub *cube, t_ray *ray, int text_x, double step, double text_pos)
{
	int i;
	int	color;
	t_text text;
	int		text_y;

	text_y = (int)text_pos;
	text_y += step;
	color = 0;
	if (*ray->side == 1)
	{
		if (*ray->dir_y > 0)
			text = cube->text[0];//east
		else
			text = cube->text[1];//west
	}
	else
	{
		if (*ray->dir_x > 0)
			text = cube->text[2];
		else
			text = cube->text[3];
	}
	i = *ray->draw_start;
	while(i <= *ray->draw_end)
	{
		text_y = (int)text_pos;
		text_pos += step;
		pixel(cube->frame, *ray->index, i, text.img.intaddr[64 * text_y + text_x]);
		i++;
	}
}

void	ray_dda(t_cub *cube, t_ray *ray)
{
	int		text_x;
	double	step;
	double	text_pos;
	//printf("test [%d]\n", *ray->pos_x);
	while (*ray->hit == 0)
	{
		if ((*ray->side_dist_x) < (*ray->side_dist_y))
		{
			//ft_printf("[x %d < y%d]\n", (int)*ray->side_dist_x, (int)*ray->side_dist_y);
			//printf("[x %f, y%f]\n", *ray->side_dist_x, *ray->side_dist_y);
			*ray->side_dist_x = *ray->side_dist_x + *ray->delta_dist_x;
			*ray->pos_x = *ray->pos_x + *ray->step_x;
			*ray->side = 0;
			//printf("x [%f, %f]\n", *ray->side_dist_x, *ray->delta_dist_x);
		}
		else
		{
			//printf("[x %f > y%f]\n", *ray->side_dist_x, *ray->side_dist_y);
			*ray->side_dist_y = *ray->side_dist_y + *ray->delta_dist_y;
			*ray->pos_y = *ray->pos_y + *ray->step_y;
			*ray->side = 1;
			//printf("y [%f, %f]\n", *ray->side_dist_y, *ray->delta_dist_y);
		}
		if (cube->map[*ray->pos_y][*ray->pos_x] == '1')
		{
			//printf("[x %d, y%d]\n", *ray->pos_x, *ray->pos_y);
			*ray->hit = 1;
		}
	}
	//printf("[x %f, y%f]\n=================\n", *ray->side_dist_x, *ray->side_dist_y);
	//printf("test [%f, %f]\n", *ray->delta_dist_x, *ray->delta_dist_y);
	if (*ray->side == 0)
		*ray->perp_wall_dist = (*ray->side_dist_x - *ray->delta_dist_x);
	else
		*ray->perp_wall_dist = (*ray->side_dist_y - *ray->delta_dist_y);
	*ray->line_height = (int)(S_HEIGHT / *ray->perp_wall_dist);
	*ray->draw_start = -(*ray->line_height) / 2 + S_HEIGHT / 2;
	if (*ray->draw_start < 0)
		*ray->draw_start = 0;
	*ray->draw_end = *ray->line_height / 2 + S_HEIGHT / 2;
	if (*ray->draw_end >= S_HEIGHT)
		*ray->draw_end = S_HEIGHT - 1;
	if (*ray->side == 0)
		ray->wall_hit = cube->pos.y + *ray->perp_wall_dist * *ray->dir_y;
	else
		ray->wall_hit = cube->pos.x + *ray->perp_wall_dist * *ray->dir_x;
	ray->wall_hit -= (int)ray->wall_hit;
	text_x = 64 - (int)(ray->wall_hit * 64);
	step = (double)64 / *ray->line_height;
	text_pos = (*ray->draw_start - S_HEIGHT / 2 + *ray->line_height / 2) * step;
	draw_line_test(cube, ray, text_x, step, text_pos);
}

void	ray_malloc(t_ray *ray)
{
	ray->dir_y = ft_calloc(1, sizeof(double));
	ray->dir_x = ft_calloc(1, sizeof(double));
	ray->pos_x = ft_calloc(1, sizeof(int));
	ray->pos_y = ft_calloc(1, sizeof(int));
	ray->side_dist_x = ft_calloc(1, sizeof(double));
	ray->side_dist_y = ft_calloc(1, sizeof(double));
	ray->delta_dist_x = ft_calloc(1, sizeof(double));
	ray->delta_dist_y = ft_calloc(1, sizeof(double));
	ray->perp_wall_dist = ft_calloc(1, sizeof(double));
	ray->step_x = ft_calloc(1, sizeof(int));
	ray->step_y = ft_calloc(1, sizeof(int));
	ray->hit = ft_calloc(1, sizeof(int));
	ray->side = ft_calloc(1, sizeof(int));
	ray->line_height = ft_calloc(1, sizeof(int));
	ray->draw_start = ft_calloc(1, sizeof(int));
	ray->draw_end = ft_calloc(1, sizeof(int));
	ray->camera_x = ft_calloc(1, sizeof(double));
	ray->index = ft_calloc(1, sizeof(int));
}

t_ray	*ray_initiator(t_cub *cube, int index)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	ray_malloc(ray);
	*ray->index = index;
	*ray->camera_x = 2 * index / (double)S_WIDTH - 1;
	//printf("[x %f, y%f]\n", cube->pos.x, cube->pos.y);
	*ray->dir_x = (*cube->dir_x) + ((*cube->plane_x) * (*ray->camera_x));
	*ray->dir_y = (*cube->dir_y) + ((*cube->plane_y) * (*ray->camera_x));
	*ray->pos_x = (int)cube->pos.x;
	*ray->pos_y = (int)cube->pos.y;
	if (*ray->dir_x == 0)
		*ray->delta_dist_x = 1;
	else
		*ray->delta_dist_x = fabs(1 / *ray->dir_x);
	if (ray->dir_y == 0)
		*ray->delta_dist_y = 1;
	else
		*ray->delta_dist_y = fabs(1 / *ray->dir_y);
	//*ray->delta_dist_x = sqrt(1 + (*ray->dir_y * *ray->dir_y) / (*ray->dir_x * *ray->dir_x));
	//*ray->delta_dist_y = sqrt(1 + (*ray->dir_x * *ray->dir_x) / (*ray->dir_y * *ray->dir_y));
	*ray->hit = 0;
	if (*ray->dir_x < 0)
	{
		*ray->step_x = -1;
		*ray->side_dist_x = (cube->pos.x - *ray->pos_x) * *ray->delta_dist_x;
	}
	else
	{
		*ray->step_x = 1;
		*ray->side_dist_x = (*ray->pos_x + 1.0f - cube->pos.x) * *ray->delta_dist_x;
	}
	if (*ray->dir_y < 0)
	{
		*ray->step_y = -1;
		*ray->side_dist_y = (cube->pos.y - *ray->pos_y) * *ray->delta_dist_y;
	}
	else
	{
		*ray->step_y = 1;
		*ray->side_dist_y = (*ray->pos_y + 1.0 - cube->pos.y) * *ray->delta_dist_y;
	}
	//printf("[x %f, y%f]\n", *ray->side_dist_x, *ray->side_dist_y);
	ray_dda(cube, ray);
	return (ray);
}

void	fill_ray_array(t_cub *cube)
{
	int	index;

	index = 0;
	cube->ray_array = ft_calloc(S_WIDTH, sizeof(t_ray *));
	while(index < S_WIDTH)
	{
		cube->ray_array[index] = ray_initiator(cube, index);
		index++;
	}
}

void	caster_v2(t_cub *cube)
{
	fill_ray_array(cube);
}

int	raycasting(t_cub *cube)
{
	change_angle(cube);
	fill_black(cube);
	caster_v2(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->frame->img, 0, 0);
	return (1);
}
