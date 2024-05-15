#include "../../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

int	change_angle(int keycode, void *cube)
{
	t_cub *cub;

    //printf("keycode %d\n", keycode);
	cub = (t_cub*)cube;
	if (keycode == 123)
		*cub->angle -= 5;
	if (keycode == 124)
		*cub->angle += 5;
	if (keycode == 0)
		cub->pos.x -= 0.1f;
	if (keycode == 2)
		cub->pos.x += 0.1f;
	if (keycode == 1)
		cub->pos.y += 0.1f;
	if (keycode == 13)
		cub->pos.y -= 0.1f;
    if (*cub->angle == 360)
        *cub->angle = 0;
    if (*cub->angle == -1)
        *cub->angle = 359;
    if (keycode == 65307)
        close_win(cube);
	return(0);
}

void	move(t_cub *cube)
{

}
