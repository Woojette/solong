/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:22:09 by wooyang           #+#    #+#             */
/*   Updated: 2025/08/04 13:22:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_reste(char *str)
{
	int		i;
	int		n;
	int		j;
	char	*reststr;

	i = 0;
	n = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (str[n] != '\n' && n < i)
		n++;
	if (str[n] == '\n')
		n++;
	reststr = malloc(sizeof(char) * (i - n + 1));
	if (!reststr)
		return (NULL);
	while (str[n] != '\0')
	{
		reststr[j] = str[n];
		j++;
		n++;
	}
	reststr[j] = '\0';
	return (reststr);
}
