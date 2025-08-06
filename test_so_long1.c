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

int	ft_check_rectangle(char **str) // rectangle
{
	int		i;
	size_t	n;

	i = 0;
	n = ft_strlen(str[i]);
	while (str[i] != NULL)
	{
		if (ft_strlen(str[i]) != n)
			return (1);
		i++;
	}
	return (0);
}

int ft_check_element(char *str) // check 0, 1, P, C, E
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == '0')
			i++;
		else if (str[i] == 'P'|| str[i] == 'C'|| str[i] == 'E')
			i++;
		else
			break;
	}
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

int	ft_check_un(char *str, char c) // player 1, exit 1
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

int	ft_check_un_plus(char *str, char c) // collectible 1++
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

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (perror("data"), 1);
	data->fd = open("maps.ber", O_RDONLY);
	if (data->fd == -1)
		return (perror("open erreur"), 1);
	data->charread = get_next_line(data->fd);
	if (!data->charread)
		return (perror("erreur malloc"), close(data->fd), ft_free(data), 1);
	close(data->fd);
	data->charmap = ft_split(data->charread, '\n');
	if (!data->charmap)
		return (perror("split charmap"), ft_free(data), 1);
	// verifier le fichier .ber
	if (ft_check_rectangle(data->charmap) == 1) // rectangle
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	if (ft_check_element(data->charread) == 1) // check 0, 1, P, C, E
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	if (ft_check_un(data->charread, 'P') == 1) // player 1
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	if (ft_check_un(data->charread, 'E') == 1) // exit 1
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	if (ft_check_un_plus(data->charread, 'C') == 1) // collectible 1++
		return (ft_free_split_tout(data->charmap), ft_free(data), 1);
	ft_free_split_tout(data->charmap);
	ft_free(data);
	return (0);
}
