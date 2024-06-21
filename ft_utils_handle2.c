/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_handle2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:01:17 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/21 21:24:49 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_ptr(ptr));
}

int	hex_lower(va_list args)
{
	unsigned long	n;

	n = va_arg(args, unsigned long);
	return (ft_put_hex_lower(n));
}

int	hex_upper(va_list args)
{
	unsigned long	n;

	n = va_arg(args, unsigned long);
	return (ft_put_hex_upper(n));
}
