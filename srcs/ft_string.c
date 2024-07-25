#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_string.h"

int ft_strlen(char *str)
{
    int size = 0;
    while(str[size++]);
    return size - 1;
}

void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

int read_number(void)
{
    char buffer[NUMBER_BUFFER_SIZE];

    int bytes_read = read(STDIN_FILENO, buffer, NUMBER_BUFFER_SIZE);
    if(bytes_read <= 0)
        return 0;
    buffer[NUMBER_BUFFER_SIZE - 1] = '\0';

    return ft_atoi(buffer);
}

char *read_string(void)
{
    char *buffer;

    buffer = (char *)malloc(sizeof(char) * (FILENAME_BUFFER_SIZE + 1));

    int bytes_read = read(STDIN_FILENO, buffer, FILENAME_BUFFER_SIZE);
    if(bytes_read <= 0)
        return 0;
    buffer[bytes_read - 1] = '\0';

    return buffer;
}

int ft_isspace(char c)
{
    if(c == ' ' || (c >= 11 && c <= 15))
        return 1;
    return 0;
}

int ft_isdigits(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int ft_atoi(char *str)
{
    int number = 0;
    int sign = 1;
    while(ft_isspace(*str))
        str++;
    if(*str == '-')
    {
        sign = -1;
        str++;
    }
    else if(*str == '+')
        str++;
    while(ft_isdigits(*str))
    {
        number *= 10;
        number += *str - '0';
        str++;
    }
    return number * sign;
}

void ft_clearscreen(void)
{
    write(STDOUT_FILENO, "\033[2J\033[H", 7);
}

void ft_putnbr(int nbr)
{
    char digits;

    if(nbr == -2147483648)
        write(1, "-2147483648", 11);
    if(nbr < 0)
    {
        write(1, "-", 1);
        nbr = -nbr;
    }
    if(nbr / 10 > 0)
    {
        ft_putnbr(nbr / 10);
        digits = (nbr % 10) + '0';
        write(1, &digits, 1);
    }
    else
    {
        digits = nbr + '0';
        write(1, &digits, 1);
    }
}

void ft_putnbr_min(int nbr, int min, char c)
{
    int length = 0;
    int temp = nbr;
    while(temp)
    {
        length++;
        temp /= 10;
    }
    if(nbr == 0)
        length = 1;
    if(nbr < 0)
        length++;
    ft_putnbr(nbr);
    while(min > length)
    {
        write(1, &c, 1);
        length++;
    }
}
