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
#include <stdlib.h>

int	init_cube(t_cub *cube)
{
	cube->angle = malloc(1 * sizeof(double));
	if (!cube->angle)
		return (0);
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
	cube->angle = &cube->ang;
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
	return (init_cube3(cube));
}

int	init_cube3(t_cub *cube)
{
	cube->dir_y = ft_calloc(1, sizeof(double));
	if (!cube->dir_y)
		return (0);
	cube->dir_x = ft_calloc(1, sizeof(double));
	if (!cube->dir_x)
		return (0);
	cube->plane_x = ft_calloc(1, sizeof(double));
	if (!cube->plane_x)
		return (0);
	cube->plane_y = ft_calloc(1, sizeof(double));
	if (!cube->plane_y)
		return (0);
	cube->ray_array = ft_calloc(S_WIDTH, sizeof(t_ray *));
	if (!cube->ray_array)
		return (0);
	return (1);
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
