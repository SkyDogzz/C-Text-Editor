
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
