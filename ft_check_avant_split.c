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

int	ft_check_ber(char *str)
{
	int		i;
	int		j;
	char	ber[4];

	i = 0;
	j = 0;
	ber[0] = 'r';
	ber[1] = 'e';
	ber[2] = 'b';
	ber[3] = '.';
	while (str[i] != '\0')
		i++;
	i--;
	while (i >= 0 && ber[j] != '\0')
	{
		if (str[i] != ber[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

int	ft_check_element(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == '0'
			|| str[i] == '\n' || str[i] == 'P'
			|| str[i] == 'C' || str[i] == 'E')
			i++;
		else
			break ;
	}
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

int	ft_check_un(char *str, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	if (nb > 1 || nb == 0)
		return (1);
	return (0);
}

int	ft_check_un_plus(char *str, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	if (nb <= 0)
		return (1);
	return (0);
}

int	ft_check_charread_exec(char *str, t_data *data)
{
	(void)data;
	if (ft_check_element(str) == 1)
		return (ft_printf("Erreur0\n"), 1);
	if (ft_check_un(str, 'P') == 1)
		return (ft_printf("Erreur1\n"), 1);
	if (ft_check_un(str, 'E') == 1)
		return (ft_printf("Erreur2\n"), 1);
	if (ft_check_un_plus(str, 'C') == 1)
		return (ft_printf("Erreur3\n"), 1);
	return (0);
}
