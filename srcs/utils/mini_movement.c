#include "../../mlx/mlx.h"
#include "../../inc/cub3d.h"
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
		write(1, "girdi\n", 6);
		while(map[k][i] != 0)
		{
			if (map[k][i] != 'W' && map[k][i] != 'N' && map[k][i] != 'E' && map[k][i] != 'S')
				i++;
			else
			{
				*x = i;
				*y = k;
				write(1, x, 1);
				write(1, "\n", 1);
				write(1, y, 1);
				write(1, "\n", 1);
				return ;
			}
		}
		k++;
	}
}

void	*print_player(t_cub *cube)
{
	int		angle;
	void	*player;
	int		x;
	int		y;

	find_player(cube->map, &x, &y);
	printf("%s\n", cube->map[0]);
	return (NULL);
}
