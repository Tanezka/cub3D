#include "../../inc/cub3d.h"

void	wall_direction(t_cub *cube)
{
	if (cube->start_path == 'N')
	{
		*cube->dir_x = 0;
		*cube->dir_y = 1;
		*cube->plane_y = 0.0f;
		*cube->plane_x = 0.66f;
	}
	else if (cube->start_path == 'S')
	{
		*cube->dir_x = 0;
		*cube->dir_y = -1;
		*cube->plane_y = 0.0f;
		*cube->plane_x = -0.66f;
	}
	wall_direction2(cube);
}

void	wall_direction2(t_cub *cube)
{
	if (cube->start_path == 'E')
	{
		*cube->dir_x = 1;
		*cube->dir_y = 0;
		*cube->plane_y = -0.66f;
		*cube->plane_x = 0.0f;
	}
	else if (cube->start_path == 'W')
	{
		*cube->dir_x = -1;
		*cube->dir_y = 0;
		*cube->plane_y = 0.66f;
		*cube->plane_x = 0.0f;
	}
}
