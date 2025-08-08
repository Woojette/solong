/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:42:33 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/28 17:42:49 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr_hexa_max(unsigned int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb > 15)
		i += ft_putnbr_hexa_max(nb / 16);
	i += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	return (i);
}

int	ft_putnbr_hexa_min(unsigned int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb > 15)
		i += ft_putnbr_hexa_min(nb / 16);
	i += write(1, &"0123456789abcdef"[nb % 16], 1);
	return (i);
}

int	ft_putnbr_u(unsigned int n)
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

int	ft_putptr(unsigned long n)
{
	int		i;

	i = 0;
	if (n > 15)
		i += ft_putptr(n / 16);
	i += write(1, &"0123456789abcdef"[n % 16], 1);
	return (i);
}

int	ft_putpointer(void *n)
{
	int	i;

	i = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = 2;
	i += ft_putptr((unsigned long)n);
	return (i);
}
