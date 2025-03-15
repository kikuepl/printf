/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:48 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/21 22:57:43 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *ptr)
{
	unsigned long	addr;
	char			buffer[20];
	int				pos;
	int				digit;

	if (!ptr)
		return (ft_printf("(nil)"));
	addr = (unsigned long)ptr;
	pos = 19;
	buffer[pos--] = '\0';
	while (addr)
	{
		digit = addr % 16;
		if (digit < 10)
			buffer[pos--] = digit + '0';
		else
			buffer[pos--] = (digit - 10) + 'a';
		addr /= 16;
	}
	buffer[pos] = 'x';
	buffer[pos - 1] = '0';
	return (ft_printf("%s", &buffer[pos - 1]));
}

int	ft_put_hex_lower(unsigned long num)
{
	unsigned int	addr;
	char			buffer[20];
	int				pos;
	int				digit;

	addr = 0 + (unsigned long)num;
	if (!addr)
		return (ft_printf("0"));
	pos = 19;
	buffer[pos--] = '\0';
	while (addr)
	{
		digit = addr % 16;
		if (digit < 10)
			buffer[pos--] = digit + '0';
		else
			buffer[pos--] = (digit - 10) + 'a';
		addr /= 16;
	}
	return (ft_printf("%s", &buffer[pos + 1]));
}

int	ft_put_hex_upper(unsigned long num)
{
	unsigned int		addr;
	char				buffer[20];
	int					pos;
	int					digit;

	addr = 0 + (unsigned long)num;
	if (!addr)
		return (ft_printf("0"));
	pos = 19;
	buffer[pos--] = '\0';
	while (addr)
	{
		digit = addr % 16;
		if (digit < 10)
			buffer[pos--] = digit + '0';
		else
			buffer[pos--] = (digit - 10) + 'a';
		addr /= 16;
	}
	ft_str_toupper(&buffer[pos + 1]);
	return (ft_printf("%s", buffer + pos + 1));
}
