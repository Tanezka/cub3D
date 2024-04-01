#include "../../inc/cub3d.h"

int	key_press(int keycode, t_cub *var)
{
	if (keycode == 53)
		close_win(var);
	if (keycode == 13)
		var->keys.w = 1;
	if (keycode == 0)
		var->keys.a = 1;
	if (keycode == 1)
		var->keys.s = 1;
	if (keycode == 2)
		var->keys.d = 1;
	if (keycode == 123)
		var->keys.left = 1;
	if (keycode == 124)
		var->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_cub *var)
{
	if (keycode == 13)
		var->keys.w = 0;
	if (keycode == 0)
		var->keys.a = 0;
	if (keycode == 1)
		var->keys.s = 0;
	if (keycode == 2)
		var->keys.d = 0;
	if (keycode == 123)
		var->keys.left = 0;
	if (keycode == 124)
		var->keys.right = 0;
	return (0);
}
