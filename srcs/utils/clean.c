#include "../../library/mlx/mlx.h"
#include "../../inc/cub3d.h"
#include <stdlib.h>

void	clean(t_cub *cube)
{
	cube_free(cube);
	free(cube->mlx);
	exit(1);
}