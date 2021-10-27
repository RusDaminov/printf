/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:39:59 by abernita          #+#    #+#             */
/*   Updated: 2021/10/25 11:40:02 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru_fd(unsigned int n, int fd, int *count)
{
	if (n >= 10)
	{
		ft_putnbru_fd(n / 10, 1, count);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, 1);
		(*count)++;
	}
}

void	ft_u(int *count, va_list ap)
{
	unsigned int	u_d;

	u_d = va_arg(ap, unsigned int);
	ft_putnbru_fd(u_d, 1, count);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}