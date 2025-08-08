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

int	init_player(t_data *data)
{
	data->img_path = "./image/player.xpm";
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path,
			&data->img_width, &data->img_height);
	if (!data->img_player)
		return (perror("Échec du chargement de l'image"), 1);
	return (0);
}

int	init_mur(t_data *data)
{
	data->img_path = "./image/mur.xpm";
	data->img_mur = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path,
			&data->img_width, &data->img_height);
	if (!data->img_mur)
		return (perror("Échec du chargement de l'image"), 1);
	return (0);
}

int	init_calice(t_data *data)
{
	data->img_path = "./image/calice.xpm";
	data->img_calice = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path,
			&data->img_width, &data->img_height);
	if (!data->img_calice)
		return (perror("Échec du chargement de l'image"), 1);
	return (0);
}

int	init_sortie(t_data *data)
{
	data->img_path = "./image/sortie.xpm";
	data->img_sortie = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path,
			&data->img_width, &data->img_height);
	if (!data->img_sortie)
		return (perror("Échec du chargement de l'image"), 1);
	return (0);
}

int	init_sol(t_data *data)
{
	data->img_path = "./image/sol.xpm";
	data->img_sol = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path,
			&data->img_width, &data->img_height);
	if (!data->img_sol)
		return (perror("Échec du chargement de l'image"), 1);
	return (0);
}
