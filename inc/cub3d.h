#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#include <stdbool.h>
#include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct	s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef	struct s_text
{
	t_data	img;
	int		width;
	int		height;
}	t_text;

typedef struct s_render
{
	
}	t_render;

typedef struct	s_cub
{
	void	*mlx;
	void	*win;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	**map;
	char	start_path;
	int		f_color[3];
	int		c_color[3];
	int		text_x;
	int		text_y;
	int		move;
	size_t	map_width;
	size_t	map_height;
	t_point	pos;
	t_keys	keys;
	t_data	img;
	t_text	text[4];
	t_render *rend;
}	t_cub;
void	cube_free(t_cub *cube);
void	resize_map(t_cub *cube);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_strndup(char *save, int len);
char	*save_rest(char *save, int len);
int		split_len(char **split);
int		error_message(char *message);
int		map_path_check(char *map_path);
int		is_current_param(char *line, t_cub *cube, int *nbr);
int		parse_file(char *filename, t_cub *cube);
int		check_closed_map(t_cub *cube);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_notnewline(char *s);
int		ft_linelen(char *s);
int		ft_strlen(char *s);
int		init_param(t_cub *cube);
int		init_cube(t_cub *cube);
#endif