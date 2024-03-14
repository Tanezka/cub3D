#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	char	*img_path;
	int		width;
	int		height;
}	t_data;
#endif