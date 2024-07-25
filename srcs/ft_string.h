#ifndef FT_STRING_H
# define FT_STRING_H

int ft_strlen(char *str);
void ft_putstr(char *str);
int read_number(void);
char *read_string(void);
int ft_atoi(char *str);
void ft_clearscreen(void);
void ft_putnbr(int nbr);
void ft_putnbr_min(int nbr, int min, char c);

# define NUMBER_BUFFER_SIZE 32
# define FILENAME_BUFFER_SIZE 32
# define LINE_BUFFER_SIZE 4096

#endif
