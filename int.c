/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:27:24 by abernita          #+#    #+#             */
/*   Updated: 2021/10/25 11:27:27 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	else
		len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbri_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbri_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbri_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbri_fd(n / 10, fd);
		n %= 10;
		ft_putchar_fd(n + 48, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + 48, fd);
}

void	ft_d(int *count, va_list ap)
{
	int	dig;

	dig = va_arg(ap, int);
	ft_putnbri_fd(dig, 1);
	*count += f_len(dig);
}
