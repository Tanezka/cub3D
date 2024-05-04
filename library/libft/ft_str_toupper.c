#include "../../inc/cub3d.h"

char	*ft_str_toupper(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		*ptr = ft_toupper(*ptr);
		ptr++;
	}
	return (str);
}
