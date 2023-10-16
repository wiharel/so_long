SRCS = src/ft_check.c src/ft_check2.c src/ft_errors.c src/ft_init.c \
       src/ft_parser.c src/ft_strcmp.c src/get_next_line_utils.c \
       src/get_next_line.c src/key_hook.c src/main.c src/map_utils.c \
       src/mlx_utils.c src/moves_play.c src/pos.c src/render_utils.c \
       src/render.c src/sprites.c src/window.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

MLX_PATH = ./mlx_linux/
MLX_NAME = $(MLX_PATH)libmlx.a

INC = ./inc/

CC = clang -Wall -Wextra -Werror -g
RM = rm -f

CFLAGS = -lm -lmlx -lXext -lX11

all: ${NAME}

.c.o:
	${CC} -I${INC} -I${MLX_PATH} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	 make -C ${MLX_PATH}
	 ${CC} ${OBJS} ${MLX_NAME} -L${MLX_PATH} -I${INC} -I${MLX_PATH} ${CFLAGS} -o${NAME}

clean:
	make clean -C ${MLX_PATH}
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
	
re:	fclean all

.PHONY: all clean fclean re
