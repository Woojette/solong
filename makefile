CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx-linux -lmlx -lXext -lX11

SRC =	so_long.c \
	get_next_line_tout.c \
	get_next_line_utils.c \
	libft_petit.c \
	libft_split.c \
	ft_printf.c \
	ft_printf_utils.c \
	free.c \
	ft_check_avant_split.c \
	ft_check_apres_split.c \
	ft_check_chemin.c \
	ft_check_deplacement.c \
	ft_print_image.c \
	ft_charger_image.c \
	ft_init_image.c \
	ft_init_valeur.c \
	ft_init_fichier.c \
	ft_check_debut.c \
	ft_init_mlx_window.c

OBJ = ${SRC:.c=.o}

%.o:%.cc
	${CC} ${CFLAGS} ${MLX} -c $< -o $@

NAME	= so_long

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${MLX} -o ${NAME}
	# ar -rcs $@ $^

clean	:
	rm -f	${OBJ}

fclean	:	clean
	rm -f	${NAME}

re	:	fclean
	make

.PHONY: all clean fclean re
