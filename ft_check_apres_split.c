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

// rectangle
int	ft_check_rectangle(char **str)
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

int	ft_check_charmap_exec(char **str, t_data *data)
{
	if (ft_check_rectangle(str) == 1)
		return (ft_printf("Erreur\nRectangle\n"), 1);
	data->x = 0;
	data->y = 0;
	data->max_x = ft_strlen(str[0]) - 1;
	data->max_y = data->y;
	while (str[data->max_y] != NULL)
		data->max_y++;
	data->max_y -= 1;
	if (ft_check_mur(str, data) == 1)
		return (ft_printf("Erreur\nMur\n"), 1);
	return (0);
}
