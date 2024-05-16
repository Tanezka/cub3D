#include "../../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	rotate_right(t_cub *cube)
{
	double	old_dirx;
	double	old_planex;
	double	rot_speed;

	rot_speed = 0.05f;
	old_dirx = *cube->dir_x;
	*cube->dir_x = *cube->dir_x * cos(-rot_speed) - *cube->dir_y * sin(-rot_speed);
	*cube->dir_y = old_dirx * sin(-rot_speed) + *cube->dir_y * cos(-rot_speed);
	old_planex = *cube->plane_x;
	*cube->plane_x = *cube->plane_x * cos(-rot_speed)
		- *cube->plane_y * sin(-rot_speed);
	*cube->plane_y = old_planex * sin(-rot_speed)
		+ *cube->plane_y * cos(-rot_speed);
}

int	change_angle(int keycode, void *cube)
{
	t_cub	*cub;
	double	old_dirx;
	double	old_planex;
	double	rot_speed;

	rot_speed = 0.05f;
	cub = (t_cub*)cube;
	printf("keycode %d\n", keycode);
	if (keycode == 123)
	{
		old_dirx = *cub->dir_x;
		*cub->dir_x = *cub->dir_x * cos(rot_speed) - *cub->dir_y * sin(rot_speed);
		*cub->dir_y = old_dirx * sin(rot_speed) + *cub->dir_y * cos(rot_speed);
		old_planex = *cub->plane_x;
		*cub->plane_x = *cub->plane_x * cos(rot_speed) - *cub->plane_y * sin(rot_speed);
		*cub->plane_y = old_planex * sin(rot_speed) + *cub->plane_y * cos(rot_speed);
	}
	if (keycode == 124)
		rotate_right(cub);

	return(0);
}
/*
	*123 left arrow, 124 right arrow
	w = 13
	a = 0
	s = 1
	d = 2
	* 
	* 
	* */

void	move(t_cub *cube)
{

}
