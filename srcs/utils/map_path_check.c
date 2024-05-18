#include "../../inc/cub3d.h"

int	map_path_check(char *map_path)
{
	if (ft_strcmp(map_path + ft_strlen(map_path) - 4, ".cub") != 0)
		error_message("Wrong file format should have .cub extension");
	return (1);
}
