#include <unistd.h>
#include "ftstring.h"

void display_menu(void);
void main_loop(void);

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    main_loop();

    return 0;
}

void main_loop(void)
{
    int number;

    while(1)
    {
        display_menu();
        number = read_number();
        ft_clearscreen();
        if(number == 1)
            ft_putstr("Open file: TODO\n");
        else if(number == 2)
            ft_putstr("Create file: TODO\n");
        else if(number == 3)
            ft_putstr("Edit file: TODO\n");
        else if(number == 4)
            ft_putstr("Save file: TODO\n");
        else if(number == 5)
            return ;
        else
            ft_putstr("Invalid choice, please try again.\n");
    }
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
