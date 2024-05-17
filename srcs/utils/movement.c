#include "../../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	rotate_right(t_cub *cube)
{
	cube->rot_speed = 0.15f;
	cube->old_dirx = *cube->dir_x;
	*cube->dir_x = *cube->dir_x * cos(-cube->rot_speed) - *cube->dir_y * sin(-cube->rot_speed);
	*cube->dir_y = cube->old_dirx * sin(-cube->rot_speed) + *cube->dir_y * cos(-cube->rot_speed);
	cube->old_planex = *cube->plane_x;
	*cube->plane_x = *cube->plane_x * cos(-cube->rot_speed)
		- *cube->plane_y * sin(-cube->rot_speed);
	*cube->plane_y = cube->old_planex * sin(-cube->rot_speed)
		+ *cube->plane_y * cos(-cube->rot_speed);
}

void	rotate_left(t_cub *cube)
{
	cube->old_dirx = *cube->dir_x;
	*cube->dir_x = *cube->dir_x * cos(cube->rot_speed) - *cube->dir_y * sin(cube->rot_speed);
	*cube->dir_y = cube->old_dirx * sin(cube->rot_speed) + *cube->dir_y * cos(cube->rot_speed);
	cube->old_planex = *cube->plane_x;
	*cube->plane_x = *cube->plane_x * cos(cube->rot_speed) - *cube->plane_y * sin(cube->rot_speed);
	*cube->plane_y = cube->old_planex * sin(cube->rot_speed) + *cube->plane_y * cos(cube->rot_speed);
}

void	move_straight(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x + *cube->dir_x * 0.1)] != '1')
		cube->pos.x += *cube->dir_x * 0.1;
	if (cube->map[(int)(cube->pos.y + *cube->dir_y * 0.1)][(int)(cube->pos.x)] != '1')
		cube->pos.y += *cube->dir_y * 0.1;
}

void	move_back(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x - *cube->dir_x * 0.1)] != '1')
		cube->pos.x -= *cube->dir_x * 0.1;
	if (cube->map[(int)(cube->pos.y - *cube->dir_y * 0.1)][(int)(cube->pos.x)] != '1')
		cube->pos.y -= *cube->dir_y * 0.1;
}

void	move_left(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x - *cube->plane_x * 0.1)] != '1')
		cube->pos.x -= *cube->plane_x * 0.1;
	if (cube->map[(int)(cube->pos.y - *cube->plane_y * 0.1)][(int)(cube->pos.x)] != '1')
		cube->pos.y -= *cube->plane_y * 0.1;
}

void	move_right(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x + *cube->plane_x * 0.1)] != '1')
		cube->pos.x += *cube->plane_x * 0.1;
	if (cube->map[(int)(cube->pos.y + *cube->plane_y * 0.1)][(int)(cube->pos.x)] != '1')
		cube->pos.y += *cube->plane_y * 0.1;
}


int	change_angle(int keycode, t_cub *cube)
{
	cube->rot_speed = 0.15f;
	printf("keycode %d\n", keycode);
	if (keycode == 123)
		rotate_left(cube);
	if (keycode == 124)
		rotate_right(cube);
	if (keycode == 13)
		move_straight(cube);
	if (keycode == 1)
		move_back(cube);
	if (keycode == 0)
		move_left(cube);
	if (keycode == 2)
		move_right(cube);
	return(0);
}

