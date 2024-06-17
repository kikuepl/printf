/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:38 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/17 18:30:05 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int ft_printf(const char *format, ...)
// {
//     va_list args;
//     va_start(args, format);

//     printf("%s", args);
//     return 0;
// }

// int main()
// {
//     ft_printf("%s\n", "Hello World");
//     return 0;
// }


int ft_printf(const char *format, ...)
{
    int     res;
    va_list args;
    va_start(args, format);

    res = 0;
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    ft_putchar_fd(va_arg(args, int),1);
                    res++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (!str) str = "(null)";
                    ft_putstr_fd(str, 1);
                    res += ft_strlen(str);
                    break;
                }
                case 'd':
                case 'i':
                {
                    int n = va_arg(args, int);
                    res += ft_numdigit(n);
                    ft_putnbr_fd(n,1);
                    break;
                }
                case 'p':
                {
                    void *ptr = va_arg(args, void *);
                    res += ft_unko(ptr);
                    break;
                }
                case 'u':
                {
                    unsigned int n = va_arg(args, unsigned int);
                    res += ft_numdigit(n);
                    ft_putunbr_fd(n,1);
                    break;
                }
                case 'x':
                {
                    unsigned long n = va_arg(args, unsigned long);
                    res += ft_chinko(n);
                    break;
                }
                case 'X':
                {
                    unsigned long n = va_arg(args, unsigned long);
                    res += ft_manko(n);
                    break;
                }
                case '%':
                {
                    ft_putchar_fd(*format, 1);
                    res++;
                    break;
                }
            }
        } else
        {
            ft_putchar_fd(*format, 1);
            res++;
        }
        format++;
    }
    va_end(args);
    
    return res;
}

// int main()
// {
//     // int siz1 = ft_printf("%s", (char *)NULL);
//     // int siz2 = printf("%s", (char *)NULL);
//     int siz1 = ft_printf("    %%\n");
//     int siz2 = printf("    %%\n");
//     printf("%d\n", siz1);
//     printf("%d\n", siz2);
//     // ft_printf("%s\n", "Hello World");
//     // ft_printf("%d\n", 123);
//     // ft_printf("%i\n", 6);
//     return 0;
// }