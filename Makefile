NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -framework OpenGL -framework AppKit mlx/libmlx.a
SRCS =	srcs/main.c \
		srcs/line_read/line_reading.c \
		srcs/line_read/line_reading_utils.c \
		srcs/utils/free.c \
		srcs/utils/utils.c \
		srcs/utils/hook.c \
		srcs/utils/init_cube.c \
		srcs/utils/mini_movement.c \
		srcs/utils/pixel_put.c\
		srcs/parse/parse_map.c \
		srcs/parse/parse.c \
		srcs/parse/utils.c \
		srcs/raycast/raycast.c \
		srcs/raycast/textures.c \
		srcs/libft/ft_atoi.c \
		srcs/libft/ft_calloc.c \
		srcs/libft/ft_memset.c \
		srcs/libft/ft_strchr.c \
		srcs/libft/ft_strdup.c \
		srcs/libft/ft_strcmp.c \
		srcs/libft/ft_split.c \
		srcs/libft/ft_bzero.c \
		srcs/libft/ft_str_toupper.c \
		srcs/libft/ft_toupper.c
OBJS_DIR = obj/
OBJS = $(SRCS:.c=.o)
OBJS_PRE = $(addprefix $(OBJS_DIR), $(OBJS))
RM = rm -rf

RED = \x1b[31;01m
GREEN = \x1b[32;01m
BLUE = \033[34;1m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(OBJS_PRE)
	@$ $(CC) $(CFLAGS) $(OBJS_PRE) $(LIBS) -o $(NAME)
	@printf "$(GREEN) Executable named cub3D created$(RESET)\n"

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)
	@printf "$(BLUE) Deleting object files$(RESET)\n"

fclean:
	@$(RM) $(NAME) $(OBJS_DIR)
	@printf "$(RED) Deleting executable filename and object file$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
