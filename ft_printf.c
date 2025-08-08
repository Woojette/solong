/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:37:38 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/28 17:47:09 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		i++;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_afficher(const char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i + 1] == 'c')
		count += ft_putchar(va_arg(args, int));
	if (str[i + 1] == 's')
		count += ft_putstr(va_arg(args, char *));
	if (str[i + 1] == 'p')
		count += ft_putpointer(va_arg(args, void *));
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (str[i + 1] == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	if (str[i + 1] == 'x')
		count += ft_putnbr_hexa_min(va_arg(args, unsigned int));
	if (str[i + 1] == 'X')
		count += ft_putnbr_hexa_max(va_arg(args, unsigned int));
	if (str[i + 1] == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_afficher(str, i, args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
