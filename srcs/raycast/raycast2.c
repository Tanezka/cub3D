/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:31:13 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:31:14 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

t_ray	text_initiator(t_ray *ray, t_cub *cube)
{
	ray->hit = 0;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cube->pos.x - ray->pos_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->pos_x + 1.0f - cube->pos.x) * \
		ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cube->pos.y - ray->pos_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->pos_y + 1.0 - cube->pos.y) * \
		ray->delta_dist_y;
	}
	return (*ray);
}

void	ray_dda2(t_cub *cube, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(S_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + S_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + S_HEIGHT / 2;
	if (ray->draw_end >= S_HEIGHT)
		ray->draw_end = S_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_hit = cube->pos.y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_hit = cube->pos.x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_hit -= (int)ray->wall_hit;
	ray->text_x = 64 - (int)(ray->wall_hit * 64);
	ray->step = (double)64 / ray->line_height;
	ray->text_pos = (ray->draw_start - S_HEIGHT / 2 + ray->line_height / 2) \
	* ray->step;
}

void	ray_dda(t_cub *cube, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if ((ray->side_dist_x) < (ray->side_dist_y))
		{
			ray->side_dist_x = ray->side_dist_x + ray->delta_dist_x;
			ray->pos_x = ray->pos_x + ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y = ray->side_dist_y + ray->delta_dist_y;
			ray->pos_y = ray->pos_y + ray->step_y;
			ray->side = 1;
		}
		if (cube->map[ray->pos_y][ray->pos_x] == '1')
		{
			ray->hit = 1;
		}
	}
	ray_dda2(cube, ray);
	draw_line_test(cube, ray);
}

t_ray	*ray_initiator(t_cub *cube, int index)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	ray->index = index;
	ray->camera_x = 2 * index / (double)S_WIDTH - 1;
	ray->dir_x = (*cube->dir_x) + ((*cube->plane_x) * (ray->camera_x));
	ray->dir_y = (*cube->dir_y) + ((*cube->plane_y) * (ray->camera_x));
	ray->pos_x = (int)cube->pos.x;
	ray->pos_y = (int)cube->pos.y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	text_initiator(ray, cube);
	ray_dda(cube, ray);
	return (ray);
}

void	draw_line_test2(t_cub *cube, t_ray *ray, t_text text, int i)
{
	while (i <= ray->draw_end)
	{
		ray->text_y = (int)ray->text_pos;
		ray->text_pos += ray->step;
		pixel(cube->frame, ray->index, i, text.img.int_addr[64 * ray->text_y \
		+ ray->text_x]);
		i++;
	}
}
