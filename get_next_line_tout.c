/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_tout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:21:01 by wooyang           #+#    #+#             */
/*   Updated: 2025/08/04 13:21:41 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_return(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	while (j < i)
	{
		newstr[j] = str[j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

int	my_read(int fd, int *fdread, char **charread, char **str)
{
	char	*temp;

	while (*fdread > 0)
	{
		(*charread)[*fdread] = '\0';
		temp = ft_strjoin(*str, *charread);
		if (!temp)
			return (free(*str), *str = NULL, free(*charread), -1);
		free(*str);
		*str = temp;
		if (ft_check(*str, '\0') == 1)
			break ;
		*fdread = read(fd, *charread, BUFFER_SIZE);
		if (*fdread == -1)
			return (free(*str), *str = NULL, free(*charread), -1);
	}
	free(*charread);
	return (0);
}

int	checks(int fd, char **str)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(*str), *str = NULL, -1);
	if (!*str)
	{
		*str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (-1);
		(*str)[0] = '\0';
	}
	return (0);
}

int	ft_test_null(char **charread, int *fd, char **str)
{
	int	fdread;

	*charread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*charread))
		return (-1);
	fdread = read(*fd, *charread, BUFFER_SIZE);
	if (fdread == -1)
		return (free(*str), *str = NULL, free(*charread), *charread = NULL, -1);
	if (my_read(*fd, &fdread, charread, str) == -1)
		return (-1);
	if (fdread == 0 && ((*str)[0] == '\0' || !(*str)))
	{
		if (*str)
			return (free(*str), *str = NULL, -1);
		return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*charread;
	char		*temp;
	char		*strreturn;
	static char	*str;

	if (checks(fd, &str) == -1)
		return (NULL);
	if (ft_test_null(&charread, &fd, &str) == -1)
		return (free(str), str = NULL, NULL);
	strreturn = ft_return(str);
	if (!strreturn)
		return (free(str), str = NULL, NULL);
	temp = ft_reste(str);
	if (!temp)
		return (free(str), str = NULL, free(strreturn), NULL);
	free(str);
	str = temp;
	if (str && str[0] == '\0')
		return (free(str), str = NULL, strreturn);
	return (free(str), str = NULL, strreturn);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("maps.ber", O_RDONLY);
// 	if (fd == -1)
//  	{
// 		printf("Error\n");
// 		return (1);
//  	}
// 	// str = get_next_line(fd);
// 	// while (str)
// 	// {
// 	// 	printf("[%s]", str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);
// 	// }
// 	str = get_next_line(fd);
// 	printf("[%s]", str);
// 	free(str);
// 	return (0);
// }
