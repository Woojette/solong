/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:19:18 by wooyang           #+#    #+#             */
/*   Updated: 2025/08/04 13:19:55 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(t_data *data)
{
	if (data->charread)
		free(data->charread);
	if (data)
		free(data);
	return (0);
}

void	ft_free_split_tout(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_final(t_data *data)
{
	if (data->img_player)
		mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (data->img_mur)
		mlx_destroy_image(data->mlx_ptr, data->img_mur);
	if (data->img_calice)
		mlx_destroy_image(data->mlx_ptr, data->img_calice);
	if (data->img_sortie)
		mlx_destroy_image(data->mlx_ptr, data->img_sortie);
	if (data->img_sol)
		mlx_destroy_image(data->mlx_ptr, data->img_sol);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->charmap_origine)
		ft_free_split_tout(data->charmap_origine);
	if (data->charmap)
		ft_free_split_tout(data->charmap);
	if (data)
		ft_free(data);
}

int	ft_free_final_croix(t_data *data)
{
	ft_free_final(data);
	exit (0);
}

int	ft_check_ber(char *str)
{
	int		i;
	int		j;
	char	ber[4];

	i = 0;
	j = 0;
	ber[0] = 'r';
	ber[1] = 'e';
	ber[2] = 'b';
	ber[3] = '.';
	while (str[i] != '\0')
		i++;
	i--;
	while (i >= 0 && ber[j] != '\0')
	{
		if (str[i] != ber[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

int ft_check_element(char *str) // check 0, 1, P, C, E
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == '0'
			|| str[i] == '\n' || str[i] == 'P'
			|| str[i] == 'C'|| str[i] == 'E')
			i++;
		else
			break;
	}
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

int	ft_check_un(char *str, char c) // player 1, exit 1
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	if (nb > 1 || nb == 0)
		return (1);
	return (0);
}

int	ft_check_un_plus(char *str, char c) // collectible 1+
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	if (nb <= 0)
		return (1);
	return (0);
}

int	ft_check_rectangle(char **str) // rectangle
{
	int		i;
	size_t	n;

	i = 0;
	n = ft_strlen(str[i]);
	while (str[i] != NULL)
	{
		if (ft_strlen(str[i]) != n)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_mur(char **str, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= data->max_y)
	{
		while (x <= data->max_x)
		{
			if ((y == 0 || y == data->max_y) && (str[y][x] != '1'))
				return (1);
			else if ((x == 0 || x == data->max_x) && (str[y][x] != '1'))
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	position_p(char **str, char c, t_data *data) // check position P y
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= data->max_y)
	{
		while (x <= data->max_x)
		{
			if (str[y][x] == c)
			{
				data->x = x;
				data->y = y;
				printf("x:%d y:%d\n", data->x, data->y);
				return(0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	ft_check_element_double_tableau(char **str, char c, t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y <= data->max_y)
	{
		x = 0;
		while ((str[y][x] != '\0') && (x <= data->max_x))
		{
			if (str[y][x] == c)
				i++;
			x++;
		}
		y++;
	}
	if (i >= 1)
		return (1);
	return (0);
}

int	ft_check_p_avec_espace(char **str, int y, int x, t_data *data)
{
	int	resultat;

	resultat = 0;
	// ft_printf("y = %d / x = %d\n", y, x);
	if (y < 0 || x < 0 || y > data->max_y || x > data->max_x)
		return (0);
	if (str[y][x] == '1' || str[y][x] == ' ' || str[y][x] == 'E')
		return (0);
	str[y][x] = ' ';
	if (ft_check_p_avec_espace(str, y-1, x, data) == 1)
		resultat = 2;
	if (ft_check_p_avec_espace(str, y, x-1, data) == 1)
		resultat = 2;
	if (ft_check_p_avec_espace(str, y, x+1, data) == 1)
		resultat = 2;
	if (ft_check_p_avec_espace(str, y+1, x, data) == 1)
		resultat = 2;
	if (ft_check_element_double_tableau(str, 'C', data) == 1)
		return (1);
	position_p(str, 'E', data);
	if ((str[data->y-1][data->x] == '1' || str[data->y-1][data->x] == '0') && (str[data->y][data->x-1] == '1' || str[data->y][data->x-1] == '0')
		&& (str[data->y][data->x+1] == '1' || str[data->y][data->x+1] == '0') && (str[data->y+1][data->x] == '1' || str[data->y+1][data->x] == '0'))
		return (1);
	return (resultat);
}
void ft_print_map(char **str, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= data->max_y)
	{
		x = 0;
		while (x <= data->max_x)
		{
			ft_printf("%c", str[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

int	ft_print_image(char **str, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= data->max_y)
	{
		x = 0;
		while ((str[y][x] != '\0') && (x <= data->max_x))
		{
			if (str[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->img_mur, data->img_height * x, data->img_width * y);
			if (str[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->img_sol, data->img_height * x, data->img_width * y);
			if (str[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->img_player, data->img_height * x, data->img_width * y);
			if (str[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->img_calice, data->img_height * x, data->img_width * y);
			if (str[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->img_sortie, data->img_height * x, data->img_width * y);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_calice(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	key_deplacement(int key, t_data *data)
{
	position_p(data->charmap_origine, 'P', data);
	if (key == KEY_ESC)
	{
		ft_free_final(data);
		exit (0);
	}
	else if (key == KEY_haut || key == KEY_W)
	{
		if ((data->charmap_origine[data->y-1][data->x] == 'E') && (data->calice_ramasse == data->calice_total))
		{
			data->pas++;
			ft_free_final(data);
			exit (0);
		}
		if (data->charmap_origine[data->y-1][data->x] == 'C')
		{
			data->calice_ramasse++;
			ft_printf("calice : %d | pas : %d\n", data->calice_ramasse, data->pas);
		}
		if ((data->charmap_origine[data->y-1][data->x] != '1') && (data->charmap_origine[data->y-1][data->x] != 'E'))
		{
			data->charmap_origine[data->y-1][data->x] = 'P';
			data->charmap_origine[data->y][data->x] = '0';
			data->pas++;
			ft_printf("pas : %d\n", data->pas);
		}
	}
	else if (key == KEY_gauche || key == KEY_A)
	{
		if ((data->charmap_origine[data->y][data->x-1] == 'E') && (data->calice_ramasse == data->calice_total))
		{
			ft_free_final(data);
			exit (0);
		}
		if (data->charmap_origine[data->y][data->x-1] == 'C')
		{
			data->calice_ramasse++;
			ft_printf("calice : %d | pas : %d\n", data->calice_ramasse, data->pas);
		}
		if ((data->charmap_origine[data->y][data->x-1] != '1') && (data->charmap_origine[data->y][data->x-1] != 'E'))
		{
			data->charmap_origine[data->y][data->x-1] = 'P';
			data->charmap_origine[data->y][data->x] = '0';
			data->pas++;
			ft_printf("pas : %d\n", data->pas);
		}
	}
	else if (key == KEY_droite || key == KEY_D)
	{
		if ((data->charmap_origine[data->y][data->x+1] == 'E') && (data->calice_ramasse == data->calice_total))
		{
			ft_free_final(data);
			exit (0);
		}
		if (data->charmap_origine[data->y][data->x+1] == 'C')
		{
			data->calice_ramasse++;
			ft_printf("calice : %d | pas : %d\n", data->calice_ramasse, data->pas);
		}
		if ((data->charmap_origine[data->y][data->x+1] != '1') && (data->charmap_origine[data->y][data->x+1] != 'E'))
		{
			data->charmap_origine[data->y][data->x+1] = 'P';
			data->charmap_origine[data->y][data->x] = '0';
			data->pas++;
			ft_printf("pas : %d\n", data->pas);
		}
	}
	else if (key == KEY_bas || key == KEY_S)
	{
		if ((data->charmap_origine[data->y+1][data->x] == 'E') && (data->calice_ramasse == data->calice_total))
		{
			ft_free_final(data);
			exit (0);
		}
		if (data->charmap_origine[data->y+1][data->x] == 'C')
		{
			data->calice_ramasse++;
			ft_printf("calice : %d | pas : %d\n", data->calice_ramasse, data->pas);
		}
		if ((data->charmap_origine[data->y+1][data->x] != '1') && (data->charmap_origine[data->y+1][data->x] != 'E'))
		{
			data->charmap_origine[data->y+1][data->x] = 'P';
			data->charmap_origine[data->y][data->x] = '0';
			data->pas++;
			ft_printf("pas : %d\n", data->pas);
		}
	}
	ft_print_image(data->charmap_origine, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (perror("data"), 1);
	if (ft_check_ber(av[1]) == 1) // check fichier .ber
		return (ft_free(data), ft_printf("Erreur-1\n"), 1);
	data->fd = open(av[1], O_RDONLY);
	if (data->fd == -1)
		return (perror("open erreur"), 1);
	data->charread = get_next_line(data->fd);
	if (!data->charread)
		return (perror("erreur malloc"), close(data->fd), ft_free(data), 1);
	close(data->fd);
	// verifier le fichier entier
	if (ft_check_element(data->charread) == 1) // check 0, 1, P, C, E
		return (ft_free(data), ft_printf("Erreur0\n"), 1);
	if (ft_check_un(data->charread, 'P') == 1) // player 1
		return (ft_free(data), ft_printf("Erreur1\n"), 1);
	if (ft_check_un(data->charread, 'E') == 1) // exit 1
		return (ft_free(data), ft_printf("Erreur2\n"), 1);
	if (ft_check_un_plus(data->charread, 'C') == 1) // collectible 1+
		return (ft_free(data), ft_printf("Erreur3\n"), 1);
	// split
	data->charmap = ft_split(data->charread, '\n');
	if (!data->charmap)
		return (perror("split charmap"), ft_free(data), 1);
	if (ft_check_rectangle(data->charmap) == 1) // check rectangle
		return (ft_free_split_tout(data->charmap), ft_printf("Erreur\nRectangle\n"), ft_free(data), 1);
	// coordonnees
	data->x = 0;
	data->y = 0;
	data->max_x = ft_strlen(data->charmap[0]) - 1;
	data->max_y = data->y;
	while (data->charmap[data->max_y] != NULL)
		data->max_y++;
	data->max_y -= 1;
	if (ft_check_mur(data->charmap, data) == 1) // check mur
		return (ft_free_split_tout(data->charmap), ft_printf("Erreur\nMur\n"), ft_free(data), 1);
	// strdup (pour stocker le continu du fichier qui va etre remplacer par ' ')
	
	// position P
	// data->x = position_px(data->charmap, 'P', data);
	position_p(data->charmap, 'P', data);

	printf("TEST DEHORS:x:%d y:%d\n", data->x, data->y);
	// check autour de P
	if (ft_check_p_avec_espace(data->charmap, data->y, data->x, data) == 1)// check chemin avec ' '
	{
		ft_print_map(data->charmap, data);
		return (ft_free_split_tout(data->charmap), ft_printf("Erreur\nChemin\n"), ft_free(data), 1);
	}
	position_p(data->charmap, 'P', data); // replacer la position P
	ft_print_map(data->charmap, data);

	data->charmap_origine = ft_split(data->charread, '\n');
	if (!data->charmap_origine)
		return (perror("split charmap origine"), ft_free_split_tout(data->charmap), ft_free(data), 1);
	ft_printf("\n");
	ft_print_map(data->charmap_origine, data);

	// graphique
	// data->mlx_ptr = mal

	// initialiser la bibliothèque mlx
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_free_split_tout(data->charmap_origine);
		return (perror("init erreur"), ft_free_split_tout(data->charmap), ft_free(data), 1);
	}

	// creation de la fenetre
	data->img_height = 64;
	data->img_width = 64;
	ft_printf("TEST DEHORS:x:%d y:%d\n", data->max_x, data->max_y);
	ft_printf("TEST DEHORS:x:%d y:%d\n",  data->img_height, data->img_width);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->max_x+1) * data->img_width, (data->max_y+1)*data->img_height, "So Long");
	if (((data->max_x+1) > 30) || ((data->max_y+1) > 16))
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_free_split_tout(data->charmap_origine);
		ft_free_split_tout(data->charmap);
		return (perror("trop grand"), ft_free(data), 1);
	}
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->charmap_origine);
		return (perror("window erreur"), ft_free_split_tout(data->charmap), ft_free(data), 1);
	}

	// parcourir charmap + utiliser mlx_put_image() correspondant aux caracteres affiches
	data->img_path = "./image/player.xpm";
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, &data->img_width, &data->img_height);
	if (!data->img_player)
	{
		perror("Échec du chargement de l'image");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->charmap_origine);
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	}

	data->img_path = "./image/mur.xpm";
	data->img_mur = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, &data->img_width, &data->img_height);
	if (!data->img_mur)
	{
		perror("Échec du chargement de l'image");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->charmap_origine);
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	}

	data->img_path = "./image/calice.xpm";
	data->img_calice = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, &data->img_width, &data->img_height);
	if (!data->img_calice)
	{
		perror("Échec du chargement de l'image");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->charmap_origine);
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	}

	data->img_path = "./image/sortie.xpm";
	data->img_sortie = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, &data->img_width, &data->img_height);
	if (!data->img_sortie)
	{
		perror("Échec du chargement de l'image");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->charmap_origine);
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	}

	data->img_path = "./image/sol.xpm";
	data->img_sol = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, &data->img_width, &data->img_height);
	if (!data->img_sol)
	{
		perror("Échec du chargement de l'image");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->charmap_origine);
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	}

	// afficher l'image
	ft_print_image(data->charmap_origine, data);
	// ft_printf("calice total : %d\n", ft_check_calice(data->charread, 'C'));

	data->calice_ramasse = 0;
	data->calice_total = ft_check_calice(data->charread, 'C');
	data->pas = 0;

	// recuperer + deplacer P en fonction de la direction
	mlx_hook(data->win_ptr, DestroyNotify, 0, ft_free_final_croix, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_deplacement, data);

	mlx_loop(data->mlx_ptr);

	// free toutes les images
	ft_free_final(data);
	printf("Bon\n");
	return (0);
}
