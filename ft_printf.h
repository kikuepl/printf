/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:19:51 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/21 22:56:39 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_numdigit(long long n);
size_t	ft_putunbr_fd(long long n, int fd);
int		ft_put_hex_lower(unsigned long num);
int		ft_put_hex_upper(unsigned long num);
int		ft_ptr(void *ptr);
void	ft_toupper_str(char *str);
size_t	ft_strlen(const char *s);
int		ft_handle_char(va_list args);
int		ft_handle_string(va_list args);
int		ft_handle_int(va_list args);
int		ft_handle_unsigned(va_list args);
int		ft_handle_pointer(va_list args);
int		hex_lower(va_list args);
int		hex_upper(va_list args);
int		printf1(char format, va_list args);
int		printf2(char format, va_list args);
void	ft_str_toupper(char *buf);

#endif
