#include "../inc/cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = size * count;
	dst = malloc(tot_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

void cube_free(t_cub *cube)
{
	split_free(cube->map);
	free(cube->rend);
	free(cube->ea_path);
	free(cube->no_path);
	free(cube->we_path);
	free(cube->so_path);
}

void split_free(char **split)
{
	int i;
	
	i = 0;
	while(split[i])
		free(split[i++]);
	free(split);
}