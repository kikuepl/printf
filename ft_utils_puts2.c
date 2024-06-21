/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sytorium <sytorium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:48 by sytorium          #+#    #+#             */
/*   Updated: 2024/06/21 21:27:41 by sytorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_toupper_str(char *str)
{
    while(*str)
    {
        if (97 <= *str && *str <= 122)
            {
                *str -= 32;
            }
        str++;
    }
}

int    ft_ptr(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    char buffer[20];
    int pos = 19;

    buffer[pos--] = '\0';
    do
    {
        int digit = addr % 16;
        if(digit < 10)
            buffer[pos--] = digit + '0';
        else
            buffer[pos--] = (digit - 10) + 'a';
        addr /= 16;
    } while(addr);
    buffer[pos] = 'x';
    buffer[pos - 1] = '0'; 
    return ft_printf("%s",&buffer[pos - 1]);
}

int    ft_put_hex_lower(unsigned long num)
{
    unsigned int addr = 0 + (unsigned long)num;
    char buffer[20];
    int pos = 19;

    buffer[pos--] = '\0';
    do
    {
        int digit = addr % 16;
        if(digit < 10)
            buffer[pos--] = digit + '0';
        else
            buffer[pos--] = (digit - 10) + 'a';
        addr /= 16;
    } while(addr);
    return ft_printf("%s",&buffer[pos+1]);
}
int ft_put_hex_upper(unsigned long num)
{
    unsigned int addr = 0 + (unsigned long)num;
    char buffer[20];
    int pos = 19;
    buffer[pos--] = '\0';

    do {
        int digit = addr % 16;
        if (digit < 10)
            buffer[pos--] = digit + '0';
        else
            buffer[pos--] = (digit - 10) + 'a';
        addr /= 16;
    } while (addr && pos >= 0);

    for (int i = pos + 1; buffer[i]; i++) {
        if ('a' <= buffer[i] && buffer[i] <= 'z') {
            buffer[i] -= 32;
        }
    }

    return ft_printf("%s", buffer + pos + 1);
}
