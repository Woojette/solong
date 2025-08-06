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

# define KEY_A 97

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_ptr2;
	char	*img_path;
	void	*img_calice; //
	void	*img_mur; //
	void	*img_player; //
	void	*img_sol; //
	void	*img_sortie; //
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
	char	*charread;
	char	**charmap;
	char	**charmap_origine;
}	t_data;

// int		main(int ac, char **av);
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
#endif
