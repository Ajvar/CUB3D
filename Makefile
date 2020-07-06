NAME = Cub3D
LIBMLX_PATH = ./srcs/mlx
LIBFT_PATH = ./srcs/libft_light/
PARSER_PATH = ./srcs/parser/
GAME_PATH = ./srcs/Game/
CFLAGS = -Wall -Wextra -Werror -g
SRCS =	${LIBFT_PATH}functions1.c \
		${LIBFT_PATH}ft_utils.c \
		${LIBFT_PATH}functions2.c \
		${LIBFT_PATH}ft_split.c \
		${LIBFT_PATH}get_next_line.c \
		${LIBFT_PATH}get_next_line_utils.c \
		${PARSER_PATH}ft_errors.c \
		${PARSER_PATH}parser.c \
		${PARSER_PATH}ft_map.c \
		${GAME_PATH}ft_cub3d.c \
		${GAME_PATH}ft_parse_sprite.c \
		${GAME_PATH}ft_get_info.c \
		${GAME_PATH}ft_init.c \
		${GAME_PATH}ft_utils.c \
		${GAME_PATH}ft_key_input.c \
		${GAME_PATH}ft_move.c \
		${GAME_PATH}ft_terminate.c \
		${GAME_PATH}ft_raycaster.c \
		${GAME_PATH}ft_texture.c \
		${GAME_PATH}ft_draw_color.c \
		${GAME_PATH}ft_draw_texture.c \
		${GAME_PATH}ft_save.c \
		${GAME_PATH}ft_sprite.c \
		${GAME_PATH}ft_init_master.c \

OBJS = ${SRCS:.c=.o}
CC = gcc

$(NAME): ${OBJS}  ${LIBMLX_PATH}/libmlx.a
	 ${CC} ${CFLAGS} ${SRCS} -L ${LIBMLX_PATH} -lm -lmlx  -lX11 -lXext -o ${NAME}
all: ${NAME}

${LIBMLX_PATH}/libmlx.a:
	make -C ${LIBMLX_PATH}

clean:
	rm -rf ${OBJS}
	make clean -C ${LIBMLX_PATH}

fclean: clean
	rm -rf ${NAME}


re: fclean all

work: all clean

.PHONY: all clean fclean re
