/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:38:08 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/05 20:47:32 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numdigit(long long n)
{
	int	res;

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

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	int			flag;
	long long	num;

	num = n;
	flag = (n < 0);
	res = (char *)ft_calloc(numdigit(num) + 1, sizeof(char));
	if (!res)
		return (0);
	if (num == 0)
		res[0] = '0';
	if (flag)
	{
		res[0] = '-';
		num = -num;
	}
	i = numdigit(num) - 1 + flag;
	while (num)
	{
		res[i--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}