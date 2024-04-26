/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:54:59 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:55:01 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../mlx/mlx.h"

void	init_textures(t_cub *cube)
{
	if (!texture_load(cube, &cube->text[0], cube->no_path) || \
	!texture_load(cube, &cube->text[1], cube->so_path) || \
	!texture_load(cube, &cube->text[2], cube->we_path) || \
	!texture_load(cube, &cube->text[3], cube->ea_path))
	{
		return ;
	}
}

int	texture_load(t_cub *cube, t_text *text, char *path)
{
	if (!path || ft_strlen(path) == 0)
		return (0);
	text->img.img = mlx_xpm_file_to_image(cube->mlx, \
	path, &text->width, &text->height);
	if (text->img.img == NULL)
		return (0);
	text->img.addr = mlx_get_data_addr(text->img.img, \
	&text->img.bits_per_pixel, &text->img.line_length, \
	&text->img.endian);
	if (text->img.addr == NULL)
		return (0);
	return (1);
}
