/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:49:58 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:49:59 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (str[++i] && str[i] != '\n')
		if (!ft_isdigit(str[i]))
			return (-1);
	i = 0;
	while (str[i] >= 48 && str[i] <= '9' && str[i])
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res);
}
