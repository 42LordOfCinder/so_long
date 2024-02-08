SHELL = bash

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDE = ./include

SRCS = srcs/ft_printf.c            \
	   srcs/ft_putchar_count.c     \
	   srcs/ft_putstr_count.c      \
	   srcs/ft_putnbr_count.c      \
	   srcs/ft_putnbr_base_count.c \
	   srcs/ft_putptr_count.c

OBJS = ${SRCS:.c=.o}

# This is a minimal set of ANSI/VT100 color codes
_END=\x1b[0m
_BOLD=\x1b[1m
_UNDER=\x1b[4m
_REV=\x1b[7m
_UP=\x1b[A
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

# Inverted, i.e. colored backgrounds
_IGREY=\x1b[40m
_IRED=\x1b[41m
_IGREEN=\x1b[42m
_IYELLOW=\x1b[43m
_IBLUE=\x1b[44m
_IPURPLE=\x1b[45m
_ICYAN=\x1b[46m
_IWHITE=\x1b[47m

all: ${NAME}

${NAME}: ${OBJS}
	@printf "${_CLEAR} ${_YELLOW}${_BOLD}[${_END} Compiling       ${_BOLD}ft_printf${_END}    ${_GREEN}Done!${_END}${_YELLOW}${_BOLD} ]${_END}"
	@printf "\n ${_PURPLE}${_BOLD}[${_END} Linking         ${_BOLD}ft_printf${_END}...${_PURPLE}${_BOLD} ]${_END} "
	@ar rcs ${NAME} ${OBJS}
	@printf "${_CLEAR} ${_PURPLE}${_BOLD}[${_END} Linking         ${_BOLD}ft_printf${_END}    ${_GREEN}Done!${_END}${_PURPLE}${_BOLD} ]${_END}\n"

.c.o:
	@printf "${_CLEAR} ${_YELLOW}${_BOLD}[${_END} Compiling       ${_BOLD}ft_printf${_END}...    ${_CYAN}$<${_END}${_YELLOW}${_BOLD} ]${_END}"
	@${CC} ${CFLAGS} -I ./${INCLUDE} -c $< -o $@

clean:
	@printf " ${_RED}${_BOLD}[${_END} Cleaning        ${_BOLD}ft_printf${_END}...${_RED}${_BOLD} ]${_END}"
	@rm -f ${OBJS}
	@printf "${_CLEAR} ${_RED}${_BOLD}[ ${_END}Cleaning        ${_BOLD}ft_printf${_END}    ${_GREEN}Done!${_END}${_RED}${_BOLD} ]${_END}\n"

fclean: clean
	@printf "${_UP}${_CLEAR} ${_RED}${_BOLD}[ ${_END}Fully cleaning  ${_BOLD}ft_printf${_END}...${_RED}${_BOLD} ]${_END}"
	@rm -f ${NAME}
	@printf "${_CLEAR} ${_RED}${_BOLD}[ ${_END}Fully cleaning  ${_BOLD}ft_printf${_END}    ${_GREEN}Done!${_END}${_RED}${_BOLD} ]${_END}\n"

re: fclean all

PHONY: all clean fclean re
