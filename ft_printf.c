/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:38 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/21 21:51:36 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	va_start(args, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			res += printf1(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			res++;
		}
		format++;
	}
	va_end(args);
	return (res);
}

int	printf1(char format, va_list args)
{
	if (format == 'c')
		return (ft_handle_char(args));
	else if (format == 's')
		return (ft_handle_string(args));
	else if (format == 'd' || format == 'i')
		return (ft_handle_int(args));
	else if (format == 'u')
		return (ft_handle_unsigned(args));
	else
		return (printf2(format, args));
}

int	printf2(char format, va_list args)
{
	if (format == 'p')
		return (ft_handle_pointer(args));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'x')
		return (hex_lower(args));
	else if (format == 'X')
		return (hex_upper(args));
	else
		return (0);
}
