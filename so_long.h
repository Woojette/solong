/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:20:44 by wooyang           #+#    #+#             */
/*   Updated: 2025/08/02 02:20:45 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define KEY_ESC 65307
# define KEY_HAUT 65362
# define KEY_W 119
# define KEY_GAUCHE 65361
# define KEY_A 97
# define KEY_DROITE 65363
# define KEY_D 100
# define KEY_BAS 65364
# define KEY_S 115

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_ptr2;
	char	*img_path;
	void	*img_calice;
	void	*img_mur;
	void	*img_player;
	void	*img_sol;
	void	*img_sortie;
	int		img_width;
	int		img_height;
	int		map_x;
	int		map_y;
	int		fd;
	int		fdread;
	int		x;
	int		y;
	int		max_x;
	int		max_y;
	int		calice_ramasse;
	int		calice_total;
	int		pas;
	char	*charread;
	char	**charmap;
	char	**charmap_origine;
}	t_data;

char	*get_next_line(int fd);
int		ft_check(char *str, char c);
char	*ft_reste(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **resultat, size_t j);
char	*get_next_line_test(int fd);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_hexa_min(unsigned int n);
int		ft_putnbr_hexa_max(unsigned int n);
int		ft_putpointer(void *n);
int		ft_printf(const char *str, ...);
int		ft_free(t_data *data);
void	ft_free_split_tout(char **str);
void	ft_free_final(t_data *data);
int		ft_free_final_croix(t_data *data);
void	ft_free_image_reduite(t_data *data);
int		ft_check_ber(char *str);
int		ft_check_element(char *str);
int		ft_check_un(char *str, char c);
int		ft_check_un_plus(char *str, char c);
int		ft_check_charread_exec(char *str, t_data *data);
int		ft_check_rectangle(char **str);
int		ft_check_charmap_exec(char **str, t_data *data);
int		ft_check_mur(char **str, t_data *data);
int		position_p(char **str, char c, t_data *data);
int		ft_check_chemin_exec(t_data *data);
int		ft_check_element_double_tableau(char **str, char c, t_data *data);
int		ft_check_p_avec_espace(char **str, int y, int x, t_data *data);
void	ft_print_map(char **str, t_data *data);
void	ft_print_image_detaillee(char c, int y, int x, t_data *data);
int		ft_print_image(t_data *data);
int		key_deplacement(int key, t_data *data);
void	ft_haut(t_data *data);
int		init_player(t_data *data);
int		init_mur(t_data *data);
int		init_calice(t_data *data);
int		init_sortie(t_data *data);
int		init_sol(t_data *data);
int		init_image(t_data *data);
void	ft_init_valeur(t_data *data);
int		ft_check_calice(char *str, char c);
int		ft_init_fichier(char *str, t_data *data);
int		ft_check_debut(char *str, t_data *data);
int		ft_init_mlx_window(t_data *data);

#endif
