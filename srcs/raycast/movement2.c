#include "../../inc/cub3d.h"

void	move_right(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x + *cube->plane_x \
	* 0.1)] != '1')
		cube->pos.x += *cube->plane_x * 0.1;
	if (cube->map[(int)(cube->pos.y + *cube->plane_y * 0.1)][(int) \
	(cube->pos.x)] != '1')
		cube->pos.y += *cube->plane_y * 0.1;
}

int	change_angle(t_cub *cube)
{
	cube->rot_speed = 0.05f;
	if (cube->keys.left == true)
		rotate_left(cube);
	if (cube->keys.right == true)
		rotate_right(cube);
	if (cube->keys.w == true)
		move_straight(cube);
	if (cube->keys.s == true)
		move_back(cube);
	if (cube->keys.a == true)
		move_left(cube);
	if (cube->keys.d == true)
		move_right(cube);
	return (0);
}
