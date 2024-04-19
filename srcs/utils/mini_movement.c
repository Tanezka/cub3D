#include "../mlx/mlx.h"
#include "../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while(!!map && !!map[k] && map[k][0] != 0)
	{
		while(map[k][i] != 0)
		{

		}
	}
}

void	*print_player(t_cube *cube)
{
	int		angle;
	void	*player;
	int		x;
	int		y;

	find_player(cube->map, &x, &y);
}
