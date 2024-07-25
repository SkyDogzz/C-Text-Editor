#include <unistd.h>

int get_line(char *line, int length, int fd)
{
    int count = 0;
    char c;
    int bytes_read;

    while(count < length - 1)
    {
        bytes_read = read(fd, &c, 1);
        if(bytes_read == -1)
            return -1;
        else if(bytes_read == 0)
            break;
        line[count++] = c;
        if(c == '\n')
            break;
    }
    line[count] = '\0';
    return count;
}
