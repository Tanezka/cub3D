#include "../../inc/cub3d.h"

int	check_closed_map(t_cub *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if ((i == 0 || j == 0 || i == cube->map_height - 1 \
			|| j == cube->map_width - 1) && !(cube->map[i][j] == '1' \
			|| cube->map[i][j] == ' '))
				return (error_message("Map not closed"));
			if (cube->map[i][j] == ' ')
				if (!check_x_pivot(cube, i, j) || !check_y_pivot(cube, i, j))
					return (error_message("Map not closed"));
		}
	}
	return (1);
}

int	check_x_pivot(t_cub *cube, int y, int x)
{
	int	i;

	i = x;
	while (i < cube->map_width)
	{
		if (cube->map[y][i] == '1')
			break ;
		else if (cube->map[y][i] != ' ')
			return (0);
		i++;
	}
	i = x;
	while (i)
	{
		if (cube->map[y][i] == '1')
			break ;
		else if (cube->map[y][i] != ' ')
			return (0);
		if (i == 0)
			break ;
		i--;
	}
	return (1);
}

int	check_y_pivot(t_cub *cube, int y, int x)
{
	int	a;

	a = y;
	while (cube->map[a])
	{
		if (cube->map[a][x] == '1')
			break ;
		else if (cube->map[a][x] != ' ')
			return (0);
		a++;
	}
	a = y;
	while (cube->map[a])
	{
		if (cube->map[a][x] == '1')
			break ;
		else if (cube->map[a][x] != ' ')
			return (0);
		if (a == 0)
			break ;
		a--;
	}
	return (1);
}
