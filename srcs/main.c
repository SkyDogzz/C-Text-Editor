#include <unistd.h>
#include "ftstring.h"

void display_menu(void);

int main(int argc, char **argv)
{
    int number;
    (void) argc;
    (void) argv;

    number = read_number();
    display_menu();
}

void display_menu(void)
{
    ft_putstr("Mini Text Editor\n");
    ft_putstr("1. Open File\n");
    ft_putstr("2. Create File\n");
    ft_putstr("3. Edit File\n");
    ft_putstr("4. Save File\n");
    ft_putstr("5. Exit\n");
}
