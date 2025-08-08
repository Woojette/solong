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

void	ft_haut(t_data *data)
{
	if ((data->charmap_origine[data->y -1][data->x] == 'E')
		&& (data->calice_ramasse == data->calice_total))
	{
		data->pas++;
		ft_free_final(data);
		exit (0);
	}
	if (data->charmap_origine[data->y -1][data->x] == 'C')
	{
		data->calice_ramasse++;
		ft_printf("calice : %d\n", data->calice_ramasse);
	}
	if ((data->charmap_origine[data->y -1][data->x] != '1')
		&& (data->charmap_origine[data->y -1][data->x] != 'E'))
	{
		data->charmap_origine[data->y -1][data->x] = 'P';
		data->charmap_origine[data->y][data->x] = '0';
		data->pas++;
		ft_printf("pas : %d\n", data->pas);
	}
}

void	ft_gauche(t_data *data)
{
	if ((data->charmap_origine[data->y][data->x -1] == 'E')
		&& (data->calice_ramasse == data->calice_total))
	{
		ft_free_final(data);
		exit (0);
	}
	if (data->charmap_origine[data->y][data->x -1] == 'C')
	{
		data->calice_ramasse++;
		ft_printf("calice : %d\n", data->calice_ramasse);
	}
	if ((data->charmap_origine[data->y][data->x -1] != '1')
		&& (data->charmap_origine[data->y][data->x -1] != 'E'))
	{
		data->charmap_origine[data->y][data->x -1] = 'P';
		data->charmap_origine[data->y][data->x] = '0';
		data->pas++;
		ft_printf("pas : %d\n", data->pas);
	}
}

void	ft_droite(t_data *data)
{
	if ((data->charmap_origine[data->y][data->x +1] == 'E')
		&& (data->calice_ramasse == data->calice_total))
	{
		ft_free_final(data);
		exit (0);
	}
	if (data->charmap_origine[data->y][data->x +1] == 'C')
	{
		data->calice_ramasse++;
		ft_printf("calice : %d\n", data->calice_ramasse);
	}
	if ((data->charmap_origine[data->y][data->x +1] != '1')
		&& (data->charmap_origine[data->y][data->x +1] != 'E'))
	{
		data->charmap_origine[data->y][data->x +1] = 'P';
		data->charmap_origine[data->y][data->x] = '0';
		data->pas++;
		ft_printf("pas : %d\n", data->pas);
	}
}

void	ft_bas(t_data *data)
{
	if ((data->charmap_origine[data->y +1][data->x] == 'E')
		&& (data->calice_ramasse == data->calice_total))
	{
		ft_free_final(data);
		exit (0);
	}
	if (data->charmap_origine[data->y +1][data->x] == 'C')
	{
		data->calice_ramasse++;
		ft_printf("calice : %d\n", data->calice_ramasse);
	}
	if ((data->charmap_origine[data->y +1][data->x] != '1')
		&& (data->charmap_origine[data->y +1][data->x] != 'E'))
	{
		data->charmap_origine[data->y +1][data->x] = 'P';
		data->charmap_origine[data->y][data->x] = '0';
		data->pas++;
		ft_printf("pas : %d\n", data->pas);
	}
}

int	key_deplacement(int key, t_data *data)
{
	position_p(data->charmap_origine, 'P', data);
	if (key == KEY_ESC)
	{
		ft_free_final(data);
		exit (0);
	}
	else if (key == KEY_HAUT || key == KEY_W)
		ft_haut(data);
	else if (key == KEY_GAUCHE || key == KEY_A)
		ft_gauche(data);
	else if (key == KEY_DROITE || key == KEY_D)
		ft_droite(data);
	else if (key == KEY_BAS || key == KEY_S)
		ft_bas(data);
	ft_print_image(data);
	return (0);
}
