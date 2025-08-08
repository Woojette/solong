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

int	init_image(t_data *data)
{
	if (init_player(data) == 1)
		return (1);
	if (init_mur(data) == 1)
		return (1);
	if (init_calice(data) == 1)
		return (1);
	if (init_sortie(data) == 1)
		return (1);
	if (init_sol(data) == 1)
		return (1);
	return (0);
}
