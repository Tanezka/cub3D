#include "../../inc/cub3d.h"
#include "../../mlx/mlx.h"

int	render_next_frame(t_cub *cube)
{
	t_render	*rend;

	rend = cube->rend;
	ft_bzero(cube->img.addr, 1920 * 1080 * cube->img.bits_per_pixel / 8);
	//render_walls(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	return (1);
}
