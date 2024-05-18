/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:30:53 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:30:55 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_right(t_cub *cube)
{
	if (cube->map[(int)(cube->pos.y)][(int)(cube->pos.x + cube->plane_x \
	* 0.05)] != '1')
		cube->pos.x += cube->plane_x * 0.05;
	if (cube->map[(int)(cube->pos.y + cube->plane_y * 0.05)][(int) \
	(cube->pos.x)] != '1')
		cube->pos.y += cube->plane_y * 0.05;
}

int	change_angle(t_cub *cube)
{
	static int	k = 0;

	if (k++ == 0)
		rotate_left(cube);
	cube->rot_speed = 0.03f;
	if (cube->keys.left == true)
		rotate_left(cube);
	if (cube->keys.right == true)
		rotate_right(cube);
	if (cube->keys.w == true)
		move_straight(cube);
	if (cube->keys.s == true)
		move_back(cube);
	if (cube->keys.a == true)
		move_left(cube);
	if (cube->keys.d == true)
		move_right(cube);
	return (0);
}
