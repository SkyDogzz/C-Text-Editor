#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_string.h"
#include "ft_file.h"

void display_menu(void);
void main_loop(void);
void create_file(void);
void open_file(void);

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

    ft_clearscreen();
    while(1)
    {
        ft_clearscreen();
        display_menu();
        number = read_number();
        ft_clearscreen();
        if(number == 1)
            open_file();
        else if(number == 2)
            create_file();
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

void create_file(void)
{
    char *buffer;
    int fd;

    ft_putstr("Create file: ");
    buffer = read_string();
    fd = open(buffer, O_CREAT | O_EXCL, 0644);
    if(fd == -1)
    {
        ft_putstr("Error creating file.\n");
        return;
    }
    close(fd);
    ft_putstr("File \"");
    ft_putstr(buffer);
    ft_putstr("\" created.\n");
    ft_putstr("Enter to go next.\n");
    read_string();
    return;
}

void open_file(void)
{
    char *buffer;
    char *line;
    int fd;
    int count = 1;

    ft_putstr("Open file: ");
    buffer = read_string();
    fd = open(buffer, O_RDONLY);
    if(fd == -1)
    {
        ft_clearscreen();
        ft_putstr("Error opening file\n");
        return;
    }
    line = (char *)malloc(sizeof(char) * LINE_BUFFER_SIZE);
    if(!line)
    {
        ft_putstr("Memory allocation failed.\n");
        return;
    }
    while(get_line(line, LINE_BUFFER_SIZE, fd))
    {
        ft_putnbr_min(count, 3, ' ');
        ft_putstr(": ");
        ft_putstr(line);
        count++;
    }
    close(fd);
    ft_putstr("Enter to go next.\n");
    read_string();
    return;
}
