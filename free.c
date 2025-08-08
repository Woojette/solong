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

void	ft_free_image_reduite(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free_split_tout(data->charmap_origine);
	ft_free_split_tout(data->charmap);
	ft_free(data);
}
