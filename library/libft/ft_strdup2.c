/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:52:14 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:52:16 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdlib.h>

char	*ft_strdup2(const char *s1)
{
	char	*dup;
	int		i;
	int		lenght;

	lenght = ft_strlen(s1);
	i = 0;
	dup = malloc(sizeof(char) * lenght + 1);
	if (!dup)
		return (0);
	while (i < lenght && s1[i] != '\n')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	free((char *)s1);
	return (dup);
}
