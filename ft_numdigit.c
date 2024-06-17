/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:45:05 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/17 17:36:12 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_numdigit(long long n)
{
	long long res;

	res = (n <= 0);
	if (n < 0)
		n = -n;
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res);
}
