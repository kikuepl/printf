/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unko.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:18:44 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/21 22:17:16 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	return (ft_numdigit(n));
}

size_t	ft_putunbr_fd(long long n, int fd)
{
	unsigned int	i;

	i = 0 + n;
	n = i;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	return (ft_numdigit(n));
}

size_t	ft_numdigit(long long n)
{
	size_t	res;

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
