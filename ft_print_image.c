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

void	ft_print_image_detaillee(char c, int y, int x, t_data *data)
{
	if (data->charmap_origine[y][x] == '1' && c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_mur,
			data->img_height * x, data->img_width * y);
	if (data->charmap_origine[y][x] == '0' && c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_sol,
			data->img_height * x, data->img_width * y);
	if (data->charmap_origine[y][x] == 'P' && c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player,
			data->img_height * x, data->img_width * y);
	if (data->charmap_origine[y][x] == 'C' && c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_calice,
			data->img_height * x, data->img_width * y);
	if (data->charmap_origine[y][x] == 'E' && c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_sortie,
			data->img_height * x, data->img_width * y);
}

int	ft_print_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= data->max_y)
	{
		x = 0;
		while ((data->charmap_origine[y][x] != '\0') && (x <= data->max_x))
		{
			if (data->charmap_origine[y][x] == '1')
				ft_print_image_detaillee('1', y, x, data);
			if (data->charmap_origine[y][x] == '0')
				ft_print_image_detaillee('0', y, x, data);
			if (data->charmap_origine[y][x] == 'P')
				ft_print_image_detaillee('P', y, x, data);
			if (data->charmap_origine[y][x] == 'C')
				ft_print_image_detaillee('C', y, x, data);
			if (data->charmap_origine[y][x] == 'E')
				ft_print_image_detaillee('E', y, x, data);
			x++;
		}
		y++;
	}
	return (0);
}
