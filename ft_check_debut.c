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

int	ft_check_debut(char *str, t_data *data)
{
	if (ft_init_fichier(str, data) == 1)
		return (1);
	if (ft_check_charread_exec(data->charread, data) == 1)
		return (ft_free(data), 1);
	data->charmap = ft_split(data->charread, '\n');
	if (!data->charmap)
		return (perror("split charmap"), ft_free(data), 1);
	if (ft_check_charmap_exec(data->charmap, data) == 1)
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	if (ft_check_chemin_exec(data) == 1)
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	data->charmap_origine = ft_split(data->charread, '\n');
	if (!data->charmap_origine)
		return (perror("split charmap origine"),
			ft_free_split_tout(data->charmap), ft_free(data), 1);
	return (0);
}
