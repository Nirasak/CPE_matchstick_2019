/*
** EPITECH PROJECT, 2019
** my_octal_m.c
** File description:
** octal modifier
*/

#include "my.h"

int len_nbr_oct(unsigned int nb)
{
    int n = 0;

    if (nb == 0)
        n++;
    for (; nb > 0; n++)
        nb = nb / 8;
    return (n);
}

int my_octal_m3(int n, int var[4], int stock_n)
{
    if (var[1] == 1)
        for (int j = stock_n - n + var[3]; j > 0; j--) {
            my_putchar(' ');
            n++;
        }
    return (n);
}

int my_octal_m2(unsigned int nb, int n, int var[4], int stock_n)
{
    if (var[0] == 1)
        n++;
    if (var[1] == 0 && var[2] == 0)
        for (int j = stock_n - n + var[3] - len_nbr_oct(nb); j > 0; j--) {
            my_putchar(' ');
            n++;
        }
    if (var[0] == 1)
        my_putchar('0');
    if (var[1] == 0 && var[2] == 1)
        for (int j = stock_n - n + var[3] - len_nbr_oct(nb); j > 0; j--) {
            my_putchar('0');
            n++;
        }
    n = my_put_octal(nb, n);
    return (my_octal_m3(n, var, stock_n));
}

int my_octal_m(va_list ap, int n, char const *str, int *i)
{
    int stock_n = n;
    unsigned int nb = va_arg(ap, unsigned int);
    int var[4] = {0, 0, 0, 0};

    for (int j = *i; str[j] != 'o'; j++) {
        if (str[j] == '#' && nb != 0)
            var[0] = 1;
        if (str[j] == '-')
            var[1] = 1;
        if (str[j - 1] < '0' && str[j] == '0')
            var[2] = 1;
        if (str[j] > '0') {
            var[3] = my_getnbr(&str[j]);
            break;
        }
    }
    return (my_octal_m2(nb, n, var, stock_n));
}
