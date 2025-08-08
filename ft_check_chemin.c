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
	if (y < 0 || x < 0 || y > data->max_y || x > data->max_x)
		return (0);
	if (str[y][x] == '1' || str[y][x] == ' ' || str[y][x] == 'E')
		return (0);
	str[y][x] = ' ';
	if (ft_check_p_avec_espace(str, y -1, x, data) == 1)
		resultat = 2;
	if (ft_check_p_avec_espace(str, y, x -1, data) == 1)
		resultat = 2;
	if (ft_check_p_avec_espace(str, y, x +1, data) == 1)
		resultat = 2;
	if (ft_check_p_avec_espace(str, y +1, x, data) == 1)
		resultat = 2;
	if (ft_check_element_double_tableau(str, 'C', data) == 1)
		return (1);
	position_p(str, 'E', data);
	if ((str[data->y -1][data->x] == '1' || str[data->y -1][data->x] == '0')
		&& (str[data->y][data->x -1] == '1' || str[data->y][data->x -1] == '0')
		&& (str[data->y][data->x +1] == '1' || str[data->y][data->x +1] == '0')
		&& (str[data->y +1][data->x] == '1' || str[data->y +1][data->x] == '0'))
		return (1);
	return (resultat);
}

void	ft_print_map(char **str, t_data *data)
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

int	position_p(char **str, char c, t_data *data)
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
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	ft_check_chemin_exec(t_data *data)
{
	position_p(data->charmap, 'P', data);
	printf("TEST DEHORS:x:%d y:%d\n", data->x, data->y);
	if (ft_check_p_avec_espace(data->charmap, data->y, data->x, data) == 1)
	{
		ft_print_map(data->charmap, data);
		return (ft_printf("Erreur\nChemin\n"), 1);
	}
	position_p(data->charmap, 'P', data);
	ft_print_map(data->charmap, data);
	return (0);
}
