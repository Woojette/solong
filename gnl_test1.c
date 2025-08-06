/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:22:43 by wooyang           #+#    #+#             */
/*   Updated: 2025/08/04 13:22:56 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_calloc(int size)
{
	int		i;
	char	*newcalloc;

	i = 0;
	newcalloc = malloc(sizeof(char) * (size));
	if (!newcalloc)
		return (NULL);
	while (i < size)
	{
		newcalloc[i] = 0;
		i++;
	}
	return (newcalloc);
}

char	*ft_erreur(int readfd, char *str)
{
	if (readfd == -1)
		return (free(str), str = NULL, NULL);
	if (readfd == 0 && (str[0] == '\0' || !str))
	{
		if (str)
			return (free(str), str = NULL, NULL);
		return (NULL);
	}
	return (str);
}

void	ft_read_error(char *charread, char *str)
{
	free(charread);
	free(str);
	printf("Error\nMap empty\n");
	exit(EXIT_FAILURE);
}

char	*ft_read(int fd, char *str)
{	
	char	*temp;
	char	*charread;
	int		readfd;

	charread = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!charread)
		return (NULL);
	readfd = read(fd, charread, BUFFER_SIZE);
	if (readfd == 0)
		ft_read_error(charread, str);
	while (readfd > 0)
	{
		charread[readfd] = '\0';
		temp = ft_strjoin(str, charread);
		if (!temp)
			return (NULL);
		free(str);
		str = temp;
		if (ft_check(charread, '\0') == 1)
			break ;
		readfd = read(fd, charread, BUFFER_SIZE);
	}
	free(charread);
	return (ft_erreur(readfd, str));
}

char	*get_next_line_test(int fd)
{
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!str)
	{
		str = ft_calloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	return (str);
}
