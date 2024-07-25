#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_string.h"
#include "ft_file.h"
#include "ft_buffer.h"

void display_menu(char *error);
void main_loop(void);
void create_file(char *error);
void open_file(char *error);

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
    char error[256];

    ft_clearscreen();
    while(1)
    {
        ft_clearscreen();
        display_menu(error);
        ft_strcpy(error, "");
        number = read_number();
        ft_clearscreen();
        if(number == 1)
            open_file(error);
        else if(number == 2)
            create_file(error);
        else if(number == 3)
            ft_putstr("Edit file: TODO\n");
        else if(number == 4)
            ft_putstr("Save file: TODO\n");
        else if(number == 5)
            return;
        else
            ft_strcpy(error, "Invalid choice, please try again.\n");
    }
}

void display_menu(char *error)
{
    ft_putstr(error);
    ft_putstr("Mini Text Editor\n");
    ft_putstr("1. Open File\n");
    ft_putstr("2. Create File\n");
    ft_putstr("3. Edit File\n");
    ft_putstr("4. Save File\n");
    ft_putstr("5. Exit\n");
    ft_putstr("\nChoice: ");
}

void create_file(char *error)
{
    char *buffer;
    int fd;
    char c;

    ft_putstr("Create file: ");
    buffer = read_string();
    if (!buffer) {
        ft_strcpy(error, "Error reading input.\n\n");
        return;
    }
    fd = open(buffer, O_CREAT | O_EXCL, 0644);
    if (fd == -1)
    {
        ft_strcpy(error, "Error creating file. File may already exist.\n\n");
        free(buffer);
        return;
    }
    close(fd);
    ft_clearscreen();
    ft_putstr("File \"");
    ft_putstr(buffer);
    ft_putstr("\" created.\n");
    free(buffer);
    ft_putstr("\nPress any key to continue. ");
    disable_buffering();
    read(STDIN_FILENO, &c, 1);
    enable_buffering();
    return;
}

void open_file(char *error)
{
    char *buffer;
    char *line;
    int fd;
    int count = 1;
    char c;

    ft_putstr("Open file: ");
    buffer = read_string();
    if (!buffer) {
        ft_strcpy(error, "Error reading input.\n\n");
        return;
    }
    fd = open(buffer, O_RDONLY);
    if (fd == -1)
    {
        ft_strcpy(error, "Error opening file\n\n");
        free(buffer);
        return;
    }
    line = (char *)malloc(sizeof(char) * LINE_BUFFER_SIZE);
    if (!line)
    {
        ft_strcpy(error, "Memory allocation failed.\n\n");
        close(fd);
        free(buffer);
        return;
    }
    while (get_line(line, LINE_BUFFER_SIZE, fd))
    {
        ft_putnbr_min(count, 3, ' ');
        ft_putstr(": ");
        ft_putstr(line);
        count++;
    }
    free(line);
    close(fd);
    free(buffer);
    ft_putstr("\nPress any key to continue. ");
    disable_buffering();
    read(STDIN_FILENO, &c, 1);
    enable_buffering();
    return;
}
