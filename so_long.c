/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:19:18 by wooyang           #+#    #+#             */
/*   Updated: 2025/08/02 02:19:19 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_free(t_data *data)
{
    if (data->charread)
        free(data->charread);
    if (data)
        free(data);
    return (0);
}

void    ft_free_split_tout(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int main(void)
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (perror("data"), 1);

    data->fd = open("maps.ber", O_RDONLY);
    if (data->fd == -1)
        return (perror("open erreur\n"), 1);
    data->charread = get_next_line(data->fd);
    if (!data->charread)
        return (perror("erreur malloc\n"), close(data->fd), ft_free(data), 1);
    // printf("%s\n", data->charread);
    close(data->fd);
    data->charmap = ft_split(data->charread, '\n');
    if (!data->charmap)
        return (perror("split charmap"), ft_free(data), 1);
    ft_free_split_tout(data->charmap);
    // free(data->charread);
    // free(data);
    ft_free(data);
    return (0);
}