SHELL = bash

NAME = so_long

INCLUDE = ./include

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/game.c  \
	   srcs/main.c   \
	   srcs/parsing.c \
	   srcs/checking.c \
	   srcs/utils.c     \
	   srcs/assets.c     \
	   srcs/ui.c          \
	   srcs/foes.c         \
	   srcs/foes2.c         \
	   srcs/anim_player.c    \
	   srcs/assets_utils.c    \
	   srcs/update_player.c    \
	   srcs/chose_grass.c       \
	   srcs/draw_statics.c       \
	   srcs/draw_map.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INCLUDE = ./${LIBFT_DIR}/include

MLX = mlx/libmlx.so

MLX_DIR = mlx

_END=\x1b[0m
_BOLD=\x1b[1m
_UNDER=\x1b[4m
_REV=\x1b[7m
_UP=\x1b[a
_CLEAR=\x1b[2K\r

# Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

all: ${NAME}

${NAME}: ${MLX} ${LIBFT} ${OBJS}
	@printf "${_CLEAR} ${_YELLOW}${_BOLD}[${_END} Compiling       ${_BOLD}so_long${_END}      ${_GREEN}Done!${_END}${_YELLOW}${_BOLD} ]${_END}"
	@printf "\n ${_PURPLE}${_BOLD}[${_END} Linking         ${_BOLD}so_long${_END}...${_PURPLE}${_BOLD} ]${_END} "
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} mlx/libmlx.so -lSDL2 -I${INCLUDE} -I${LIBFT_INCLUDE} -o ${NAME}
	@printf "${_CLEAR} ${_PURPLE}${_BOLD}[${_END} Linking         ${_BOLD}so_long${_END}      ${_GREEN}Done!${_END}${_PURPLE}${_BOLD} ]${_END}\n"

${MLX}: ${MLX_DIR}
	@make -s -j -C mlx

${MLX_DIR}:
	@mkdir mlx
	@git clone git@github.com:seekrs/MacroLibX mlx

${LIBFT}:
	@make -s -C libft

%.o: %.c
	@printf "${_CLEAR} ${_YELLOW}${_BOLD}[${_END} Compiling       ${_BOLD}so_long${_END}... ${_CYAN}$<${_END}${_YELLOW}${_BOLD} ]${_END}"
	@${CC} ${CFLAGS} -I${INCLUDE} -Imlx/includes/ -c $< -o $@

clean:
	@make -s -C ${LIBFT_DIR} clean
	@rm -rf ${OBJS}
	@printf "${_CLEAR} ${_RED}${_BOLD}[ ${_END}Cleaning        ${_BOLD}so_long${_END}      ${_GREEN}Done!${_END}${_RED}${_BOLD} ]${_END}\n"

fclean:
	@make -s -C ${LIBFT_DIR} fclean
	@rm -rf ${OBJS}
	@rm -rf ${NAME}
	@printf "${_CLEAR} ${_RED}${_BOLD}[ ${_END}Fully cleaning  ${_BOLD}so_long${_END}      ${_GREEN}Done!${_END}${_RED}${_BOLD} ]${_END}\n"


re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
