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

int	ft_init_mlx_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (perror("init erreur"),
			ft_free_split_tout(data->charmap_origine),
			ft_free_split_tout(data->charmap), ft_free(data), 1);
	ft_init_valeur(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			(data->max_x +1) * data->img_width,
			(data->max_y +1) * data->img_height, "So Long");
	if (!data->win_ptr)
		return (perror("window erreur"), mlx_destroy_display(data->mlx_ptr),
			free(data->mlx_ptr), free(data->charmap_origine),
			ft_free_split_tout(data->charmap), ft_free(data), 1);
	if (((data->max_x +1) > 30) || ((data->max_y +1) > 16))
		return (perror("trop grand"), ft_free_image_reduite(data), 1);
	return (0);
}
