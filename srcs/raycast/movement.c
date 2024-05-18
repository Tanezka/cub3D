/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:30:48 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:30:50 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

void	rotate_right(t_cub *cube)
{
	cube->old_dirx = cube->dir_x;
	cube->dir_x = cube->dir_x * cos(-cube->rot_speed) - cube->dir_y \
	* sin(-cube->rot_speed);
	cube->dir_y = cube->old_dirx * sin(-cube->rot_speed) + cube->dir_y \
	* cos(-cube->rot_speed);
	cube->old_planex = cube->plane_x;
	cube->plane_x = cube->plane_x * cos(-cube->rot_speed)
		- cube->plane_y * sin(-cube->rot_speed);
	cube->plane_y = cube->old_planex * sin(-cube->rot_speed)
		+ cube->plane_y * cos(-cube->rot_speed);
}

void	rotate_left(t_cub *cube)
{
	cube->old_dirx = cube->dir_x;
	cube->dir_x = cube->dir_x * cos(cube->rot_speed) - cube->dir_y \
	* sin(cube->rot_speed);
	cube->dir_y = cube->old_dirx * sin(cube->rot_speed) + cube->dir_y \
	* cos(cube->rot_speed);
	cube->old_planex = cube->plane_x;
	cube->plane_x = cube->plane_x * cos(cube->rot_speed) - cube->plane_y \
	* sin(cube->rot_speed);
	cube->plane_y = cube->old_planex * sin(cube->rot_speed) + cube->plane_y \
	* cos(cube->rot_speed);
}

void	move_straight(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x + cube->dir_x * 0.05)] \
	!= '1')
		cube->pos.x += cube->dir_x * 0.05;
	if (cube->map[(int)(cube->pos.y + cube->dir_y * 0.05)][(int)(cube->pos.x)] \
	!= '1')
		cube->pos.y += cube->dir_y * 0.05;
}

void	move_back(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x - cube->dir_x * 0.05)] \
	!= '1')
		cube->pos.x -= cube->dir_x * 0.05;
	if (cube->map[(int)(cube->pos.y - cube->dir_y * 0.05)][(int)(cube->pos.x)] \
	!= '1')
		cube->pos.y -= cube->dir_y * 0.05;
}

void	move_left(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x - cube->plane_x \
	* 0.05)] != '1')
		cube->pos.x -= cube->plane_x * 0.05;
	if (cube->map[(int)(cube->pos.y - cube->plane_y * 0.05)][(int) \
	(cube->pos.x)] != '1')
		cube->pos.y -= cube->plane_y * 0.05;
}
