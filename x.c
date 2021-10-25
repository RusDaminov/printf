/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:28:07 by abernita          #+#    #+#             */
/*   Updated: 2021/10/25 11:28:09 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_0x(unsigned long long int n, int *count, char c)
{
	if (n >= 16)
	{
		ft_0x(n / 16, count, c);
		n %= 16;
	}
	if (n > 9 && n < 16)
	{
		if (c == 'X')
			ft_putchar_fd((n % 10) + 65, 1);
		else
			ft_putchar_fd((n % 10) + 97, 1);
	}
	else
		ft_putchar_fd(n + 48, 1);
	(*count)++;
}

void	ft_x(int *count, va_list ap, char c)
{
	unsigned int	dig;

	dig = va_arg(ap, unsigned int);
	ft_0x(dig, count, c);
}
