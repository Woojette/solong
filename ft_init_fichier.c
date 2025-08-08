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

int	ft_init_fichier(char *str, t_data *data)
{
	if (ft_check_ber(str) == 1)
		return (ft_free(data), ft_printf("Erreur-1\n"), 1);
	data->fd = open(str, O_RDONLY);
	if (data->fd == -1)
		return (perror("open erreur"), 1);
	data->charread = get_next_line(data->fd);
	if (!data->charread)
		return (perror("erreur malloc"), close(data->fd), ft_free(data), 1);
	close(data->fd);
	return (0);
}
