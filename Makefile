NAME = cub3D
CC = cc
CFLAGS = ##-Wall -Wextra -Werror -g
LIBS = -framework OpenGL -framework AppKit library/mlx/libmlx.a
SRCS =	srcs/main.c \
		srcs/utils/free.c \
		srcs/utils/split_len.c \
		srcs/utils/error_msg.c \
		srcs/utils/handle_keys.c \
		srcs/utils/init_cube.c \
		srcs/utils/map_path_check.c \
		srcs/utils/pixel_put.c\
		srcs/utils/clean.c \
		srcs/utils/map_color_code.c \
		srcs/parse/parse_map.c \
		srcs/parse/parse.c \
		srcs/parse/check_closed_map.c \
		srcs/parse/init_textures.c \
		srcs/parse/map_param_control.c \
		srcs/raycast/raycast.c \
		srcs/raycast/raycast2.c \
		srcs/raycast/movement.c \
		srcs/raycast/movement2.c \
		srcs/raycast/wall_direction.c \
		srcs/mlx_settings/mlx_sett.c \
		library/line_read/line_reading.c \
		library/line_read/line_reading_utils.c \
		library/libft/ft_atoi.c \
		library/libft/ft_calloc.c \
		library/libft/ft_memset.c \
		library/libft/ft_strchr.c \
		library/libft/ft_strdup.c \
		library/libft/ft_strcmp.c \
		library/libft/ft_split.c \
		library/libft/ft_isdigit.c \
		library/libft/ft_bzero.c \
		library/libft/ft_str_toupper.c \
		library/libft/ft_toupper.c \
		library/ft_printf/ft_printf.c
OBJS_DIR = obj/
MLX_DIR = library/mlx/
OBJS = $(SRCS:.c=.o)
OBJS_PRE = $(addprefix $(OBJS_DIR), $(OBJS))
RM = rm -rf

RED = \x1b[31;01m
GREEN = \x1b[32;01m
BLUE = \033[34;1m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(OBJS_PRE) $(MLX_DIR)libmlx.a
	@$ $(CC) $(CFLAGS) $(OBJS_PRE) $(LIBS) $(MLX) -o $(NAME)
	@printf "$(GREEN) Executable named cub3D created$(RESET)\n"

$(MLX_DIR)libmlx.a:
	@make -C $(MLX_DIR)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -C $(MLX_DIR)
	@printf "$(BLUE) Deleting object files$(RESET)\n"

fclean:
	@$(RM) $(NAME) $(OBJS_DIR)
	@make clean -C $(MLX_DIR)
	@printf "$(RED) Deleting executable filename and object file$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
