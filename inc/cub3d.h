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
# define S_WIDTH 1280
# define S_HEIGHT 720
# define FOV 120

# include <stdbool.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		*int_addr;
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

typedef struct s_ray
{
	double	dir_y;
	double	dir_x;
	double	side_dist_y;
	double	side_dist_x;
	double	delta_dist_y;
	double	delta_dist_x;
	double	perp_wall_dist;
	double	camera_x;
	double	step;
	double	text_pos;
	double	wall_hit;
	int		pos_y;
	int		pos_x;
	int		step_x;
	int		step_y;
	int		text_x;
	int		text_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		index;
}	t_ray;

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
	double		*dir_y;
	double		*dir_x;
	double		*plane_x;
	double		*plane_y;
	double		*angle;
	double		ang;
	double		old_dirx;
	double		old_planex;
	double		rot_speed;
	int			f_color[3];
	int			c_color[3];
	int			map_width;
	int			map_height;
	int			f_color_code;
	int			c_color_code;
	t_ray		**ray_array;
	t_data		*frame;
	t_point		pos;
	t_keys		keys;
	t_data		img;
	t_text		text[4];
}	t_cub;
void	cube_free(t_cub *cube);
void	resize_map(t_cub *cube);
void	all_free(t_cub *var);
void	move_right(t_cub *cube);
void	split_free(char **split);
void	rotate_left(t_cub *cube);
void	rotate_right(t_cub *cube);
void	draw_line_test2(t_cub *cube, t_ray *ray, t_text text, int i);
void	move_straight(t_cub *cube);
void	move_left(t_cub *cube);
void	move_back(t_cub *cube);
void	ft_bzero(void *str, size_t n);
void	init_textures(t_cub *cube);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	clean(t_cub *cube);
void	mlx_sett(t_cub *cube);
void	wall_direction(t_cub *cube);
void	ray_malloc(t_ray *ray);
void	draw_line_test(t_cub *cube, t_ray *ray);
void	wall_direction2(t_cub *cube);
void	ray_dda2(t_cub *cube, t_ray *ray);
void	map_color_code(t_cub	*cube);
void	pixel(t_data *data, int x, int y, int color);
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
int		init_cube3(t_cub *cube);
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
int		change_angle(t_cub *cube);
t_data	get_image(t_cub *cube, char *path);
t_ray	text_initiator(t_ray *ray, t_cub *cube);
t_ray	*ray_initiator(t_cub *cube, int index);
#endif
