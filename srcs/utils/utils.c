#include "../../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

int	error_message(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	close_win(t_cub *var)
{
	all_free(var);
	exit(0);
}
