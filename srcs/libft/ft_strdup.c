#include "../../inc/cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		lenght;

	lenght = ft_strlen(s1);
	i = 0;
	dup = malloc(sizeof(char) * lenght + 1);
	if (!dup)
		return (0);
	while (i < lenght)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
