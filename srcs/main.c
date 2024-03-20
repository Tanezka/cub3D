#include "../mlx/mlx.h"
#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    t_cub cube;

    if (ac != 2)
        error_message("Invalid number of arguments");
    if (!init_cube(&cube))
        error_message("Failed to initialize cube");
    cube.mlx = mlx_init();
}