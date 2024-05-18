/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:31:59 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:32:00 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/mlx/mlx.h"
#include "../../inc/cub3d.h"
#include <stdlib.h>

void	clean(t_cub *cube)
{
	cube_free(cube);
	free(cube->mlx);
	exit(1);
}
