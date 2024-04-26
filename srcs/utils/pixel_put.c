#include "../../library/mlx/mlx.h"
#include "../../inc/cub3d.h"
#include <stdlib.h>

void	pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
