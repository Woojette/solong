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

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (perror("data"), 1);
	if (ft_check_debut(av[1], data) == 1)
		return (1);
	if (ft_init_mlx_window(data) == 1)
		return (1);
	if (init_image(data) == 1)
		return (ft_free_image_reduite(data), 1);
	ft_print_image(data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, ft_free_final_croix, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_deplacement, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
