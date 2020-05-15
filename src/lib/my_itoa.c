/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_itoa.c
*/

#include "my.h"

int	my_int_len(int nb)
{
    int	div = 1;
    int	count = 1;
    int neg = (nb < 0) ? 1 : 0;

    while (nb / div >= 1) {
        div = div * 10;
        count = count + 1;
    }
    if (neg)
        count++;
    return (count);
}

char *my_itoa(int nb)
{
    int	div = 10;
    int	i = my_int_len(nb);
    char *str = malloc(sizeof(char) * i);
    int neg = (nb < 0) ? 1 : 0;

    nb = (nb < 0) ? nb * -1 : nb;
    if (nb == 0)
        return "0";
    i = i - 1;
    str[i] = '\0';
    while (i > 0) {
        str[i - 1] = (nb % div) + 48;
        nb = nb / 10;
        i = i - 1;
    }
    if (neg)
        str = my_strcat("-", str);
    return (str);
}