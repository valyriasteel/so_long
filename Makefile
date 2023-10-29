NAME = so_long
FLAGS = -framework OpenGL -framework AppKit
CC = gcc -Wall -Wextra -Werror
SRCS = ./src/so_long.c ./src/init.c src/read_map.c src/utils.c src/mlx_events.c src/update.c src/collision.c src/print.c src/check_map.c src/utils2.c ft_printf/ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): minilibx
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) ./mlx/libmlx.a

minilibx:
	make -C ./mlx

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean flcean re
