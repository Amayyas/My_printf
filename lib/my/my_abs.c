/*
** EPITECH PROJECT, 2024
** my_abs.c
** File description:
** Get abs value of number
*/

int my_abs(int nb)
{
    if (nb < 0) {
        nb = -nb;
    }
    return (nb);
}
