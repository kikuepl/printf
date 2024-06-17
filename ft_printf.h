/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:19:51 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/17 18:13:27 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
long long	ft_numdigit(long long n);
int    ft_unko(void *ptr);
void	ft_putunbr_fd(long long n, int fd);
int    ft_chinko(unsigned long ptr);
int ft_manko(unsigned long num);
void ft_toupper_str(char *str);


#endif
