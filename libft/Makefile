SHELL = bash

NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDE = ./include

FT_PRINTF_DIR = ./ft_printf

FT_PRINTF = ${FT_PRINTF_DIR}/libftprintf.a

FT_PRINTF_INCLUDE = ${FT_PRINTF_DIR}/include

SRCS = ft_atoi.c         \
	   ft_bzero.c        \
	   ft_calloc.c       \
	   ft_isalnum.c      \
	   ft_isalpha.c      \
	   ft_isascii.c      \
	   ft_isdigit.c      \
	   ft_isprint.c      \
	   ft_memchr.c       \
	   ft_memcmp.c       \
	   ft_memcpy.c       \
	   ft_memmove.c      \
	   ft_memset.c       \
	   ft_strchr.c       \
	   ft_strdup.c       \
	   ft_strlcat.c      \
	   ft_strlcpy.c      \
	   ft_strlen.c       \
	   ft_tablen.c       \
	   ft_strncmp.c      \
	   ft_strnstr.c      \
	   ft_strrchr.c      \
	   ft_tolower.c      \
	   ft_toupper.c      \
	   ft_substr.c       \
	   ft_strjoin.c      \
	   ft_strtrim.c      \
	   ft_split.c        \
	   ft_putchar_fd.c   \
	   ft_putstr_fd.c    \
	   ft_putendl_fd.c   \
	   ft_putnbr_fd.c    \
	   ft_striteri.c     \
	   ft_strmapi.c      \
	   ft_itoa.c         \
	   get_next_line.c   \
	   ft_lstnew.c       \
	   ft_lstadd_front.c \
	   ft_lstsize.c      \
	   ft_lstlast.c      \
	   ft_lstadd_back.c  \
	   ft_lstdelone.c    \
	   ft_lstclear.c     \
	   ft_lstiter.c      \
	   ft_lstmap.c       \
	   ft_lstfree.c      \
	   ft_free_tab.c     \
	   ft_tabcpy.c       \
	   ft_remove_char.c  \
	   ft_inset.c        \
	   ft_add_element_tab.c \
	   ft_printf/srcs/ft_printf.c            \
	   ft_printf/srcs/ft_putchar_count.c     \
	   ft_printf/srcs/ft_putnbr_base_count.c \
	   ft_printf/srcs/ft_putnbr_count.c      \
	   ft_printf/srcs/ft_putptr_count.c      \
	   ft_printf/srcs/ft_putstr_count.c

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

${NAME}: ${FT_PRINTF} ${OBJS}
	@printf "${_CLEAR} ${_YELLOW}${_BOLD}[${_END} Compiling       ${_BOLD}libft${_END}        ${_GREEN}Done!${_END}${_YELLOW}${_BOLD} ]${_END}"
	@printf "\n ${_PURPLE}${_BOLD}[${_END} Linking         ${_BOLD}libft${_END}...${_PURPLE}${_BOLD} ]${_END} "
	@ar rcs ${NAME} ${OBJS} ${FT_PRINTF}
	@printf "${_CLEAR} ${_PURPLE}${_BOLD}[${_END} Linking         ${_BOLD}libft${_END}        ${_GREEN}Done!${_END}${_PURPLE}${_BOLD} ]${_END}\n"


${FT_PRINTF}:
	@make -s -C ${FT_PRINTF_DIR}

.c.o:
	@printf "${_CLEAR} ${_YELLOW}${_BOLD}[${_END} Compiling       ${_BOLD}libft${_END}... ${_CYAN}$<${_END}${_YELLOW}${_BOLD} ]${_END}"
	@${CC} ${CFLAGS} -I${FT_PRINTF_INCLUDE} -I${INCLUDE} -c $< -o $@

clean:
	@make -s -C ${FT_PRINTF_DIR} clean
	@printf " ${_RED}${_BOLD}[${_END} Cleaning        ${_BOLD}libft${_END}...${_RED}${_BOLD} ]${_END}"
	@rm -f ${OBJS}
	@printf "${_CLEAR} ${_RED}${_BOLD}[ ${_END}Cleaning        ${_BOLD}libft${_END}        ${_GREEN}Done!${_END}${_RED}${_BOLD} ]${_END}\n"

fclean:
	@make -s -C ${FT_PRINTF_DIR} fclean
	@printf " ${_RED}${_BOLD}[ ${_END}Fully cleaning  ${_BOLD}libft${_END}...${_RED}${_BOLD} ]${_END}"
	@rm -f ${OBJS}
	@rm -f ${NAME}
	@printf "${_CLEAR} ${_RED}${_BOLD}[ ${_END}Fully cleaning  ${_BOLD}libft${_END}        ${_GREEN}Done!${_END}${_RED}${_BOLD} ]${_END}\n"

re: fclean all

.PHONY: all clean fclean re
