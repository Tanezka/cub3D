#include "../../inc/cub3d.h"
#include <stdio.h>

void	set_angle(double *angle, char c)
{
	int	x;

	if (c == 'N')
		x = 90;
	else if (c == 'W')
		x = 180;
	else if (c == 'S')
		x = 270;
	else if (c == 'E')
		x = 0;
	*angle = (double)x;
}

void	find_player(char **map, int *x, int *y, double *angle)
{
	int	i;
	int	k;

	k = 0;
	while(!!map && !!map[k] && map[k][0] != 0)
	{
		i = 0;
		while(map[k][i] != 0)
		{
			if (map[k][i] == 'W' || map[k][i] == 'N' || map[k][i] == 'E' || map[k][i] == 'S')
			{
				*x = i;
				*y = k;
				set_angle(angle, map[k][i]);
				return ;
			}
			i++;
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

	find_player(cube->map, &x, &y, cube->angle);

	//cube->pos.x = (double)x;
	//cube->pos.y = (double)y;
	//printf("%f  %f\n", cube->pos.x, cube->pos.y);

	cube->pos.x = (double)x + 0.5f;
	cube->pos.y = (double)y + 0.5f;
	printf("%f, %f\n", cube->pos.x, cube->pos.y);
	return (NULL);
}
