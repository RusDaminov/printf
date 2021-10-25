/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:26:23 by abernita          #+#    #+#             */
/*   Updated: 2021/10/25 11:26:25 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

void	ft_c(int *count, va_list ap);
void	ft_s(int *count, va_list ap);
void	ft_p(int *count, va_list ap);
void	ft_d(int *count, va_list ap);
void	ft_u(int *count, va_list ap);
void	ft_x(int *count, va_list ap, char c);

void	ft_0x(unsigned long long int n, int *count, char c);

void	ft_putchar_fd(char c, int fd);

#endif