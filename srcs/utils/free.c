#include "../../inc/cub3d.h"
#include <stdlib.h>

void	cube_free(t_cub *cube)
{
	split_free(cube->map);
	free(cube->rend);
	free(cube->ea_path);
	free(cube->no_path);
	free(cube->we_path);
	free(cube->so_path);
}

static void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}