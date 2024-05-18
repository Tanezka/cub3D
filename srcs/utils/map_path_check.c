/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:32:25 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:32:26 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_path_check(char *map_path)
{
	if (ft_strcmp(map_path + ft_strlen(map_path) - 4, ".cub") != 0)
		error_message("Wrong file format should have .cub extension");
	return (1);
}
