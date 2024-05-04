/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:56:51 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:56:53 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_press(int keycode, t_cub *var)
{
	if (keycode == 53)
		close_win(var);
	if (keycode == 13)
		var->keys.w = true;
	if (keycode == 0)
		var->keys.a = true;
	if (keycode == 1)
		var->keys.s = true;
	if (keycode == 2)
		var->keys.d = true;
	if (keycode == 123)
		var->keys.left = true;
	if (keycode == 124)
		var->keys.right = true;
	return (0);
}

int	key_release(int keycode, t_cub *var)
{
	if (keycode == 13)
		var->keys.w = false;
	if (keycode == 0)
		var->keys.a = false;
	if (keycode == 1)
		var->keys.s = false;
	if (keycode == 2)
		var->keys.d = false;
	if (keycode == 123)
		var->keys.left = false;
	if (keycode == 124)
		var->keys.right = false;
	return (0);
}
