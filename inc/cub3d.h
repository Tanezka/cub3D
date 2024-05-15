/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:34:33 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/02 11:34:35 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 4
# define S_WIDTH 1920
# define S_HEIGHT 1080
# define FOV 120

# include <stdbool.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_text
{
	t_data	img;
	int		width;
	int		height;
}	t_text;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	char		start_path;
	double		*angle;
	double		ang;
	int			f_color[3];
	int			c_color[3];
	int			text_x;
	int			text_y;
	int			map_width;
	int			map_height;
	t_data		*frame;
	t_point		pos;
	t_keys		keys;
	t_data		img;
	t_data		test;
	t_text		text[4];
}	t_cub;
void	cube_free(t_cub *cube);
void	resize_map(t_cub *cube);
void	all_free(t_cub *var);
void	split_free(char **split);
void	ft_bzero(void *str, size_t n);
void	init_textures(t_cub *cube);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	handle_neg_scale(int *x, int *width, int *y, int *height);
void	*print_player(t_cub *cube);
void	clean(t_cub *cube);
void	set_angle(double *angle, char c);
void	east_ray(t_cub *cube, int index);
void	ray_casting(t_cub *cube, double angle, int index);
void	caster(t_cub *cube);
void	mlx_sett(t_cub *cube);
void	find_player(char **map, int *x, int *y, double *angle);
void	pixel(t_data *data, int x, int y, int color);
void	draw_rectangle (void *frame, int x, int y, int color, int height);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*line_reading(int fd);
char	*ft_strndup(char *save, int len);
char	*save_rest(char *save, int len);
char	*ft_str_toupper(char *str);
int		split_len(char **split);
int		ft_printf(const char *str, ...);
int		ft_toupper(int c);
int		error_message(char *message);
int		map_path_check(char *map_path);
int		parse_file(char *filename, t_cub *cube);
int		check_closed_map(t_cub *cube);
int		is_current_param(char *line, t_cub *cube, int *nbr);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_notnewline(char *s);
int		ft_linelen(char *s);
int		ft_strlen(const char *s);
int		raycasting(t_cub *cube);
int		ft_isdigit(int c);
int		init_cube2(t_cub *cube);
int		texture_load(t_cub *cube, t_text *text, char *path);
int		close_win(t_cub *var);
int		init_cube(t_cub *cube);
int		parse_line(char *line, t_cub *cube, int *nbr);
int		key_press(int keycode, t_cub *var);
int		key_release(int keycode, t_cub *var);
int		parse_map(char *line, t_cub *cube);
int		check_y_pivot(t_cub *cube, int y, int x);
int		check_x_pivot(t_cub *cube, int y, int x);
int		check_path_color(t_cub *cube);
int		check_current_map_line(char *line, t_cub *cube);
int		check_color(char **split, t_cub *cube, int *nbr);
int		check_direct_path(char **split, t_cub *cube, int *nbr);
int		change_angle(int keycode, void *cube);
t_data	get_image(t_cub *cube, char *path);
void	draw_line (void *frame, int index, int color, int height);
#endif
