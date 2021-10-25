/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:26:09 by abernita          #+#    #+#             */
/*   Updated: 2021/10/25 11:26:11 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_ap(const char *str, int *count, va_list ap)
{
	if (*str == 'c')
		ft_c(count, ap);
	else if (*str == 's')
		ft_s(count, ap);
	else if (*str == 'p')
		ft_p(count, ap);
	else if (*str == 'd' || *str == 'i')
		ft_d(count, ap);
	else if (*str == 'u')
		ft_u(count, ap);
	else if (*str == 'x' || *str == 'X')
		ft_x(count, ap, *str);
	else if (*str == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else
	{
		write(1, str, 1);
		(*count)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if_ap(++str, &count, ap);
			str++;
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}

void	ft_c(int *count, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	(*count)++;
}

void	ft_s(int *count, va_list ap)
{
	char	*s;
	int		len;

	len = 0;
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)\0";
	while (s[len])
		len++;
	write(1, s, len);
	*count += len;
}

void	ft_p(int *count, va_list ap)
{
	unsigned long long int	p;

	p = va_arg(ap, unsigned long long int);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	*count += 2;
	ft_0x(p, count, 'x');
}
