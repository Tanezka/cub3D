NAME = cub3D
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBS = -framework OpenGL -framework AppKit ./mlx/libmlx.a -lz
SRCS = main.c
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
	@mkdir -p $(OBJS_DIR)
	@$ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)
	@printf "$(BLUE) Deleting object files$(RESET)\n"

fclean:
	@$(RM) $(NAME) $(OBJS_DIR)
	@printf "$(RED) Deleting executable filename and object file$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re