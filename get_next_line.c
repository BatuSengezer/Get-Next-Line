#include "get_next_line.h"

char *ft_last_line(int fd,char *last_line)
{

}

char *ft_next_line(char *last_line)
{


}

//strdup to last line and dont forget to free
char *ft_next_last_line(char *last_line)
{

}

char *get_next_line(int fd)
{
    char *next_line;
    static char *last_line;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) != 0)
        return(NULL);
    last_line = ft_last_line(fd, last_line);
    if (!last_line)
        return (NULL);
    next_line = ft_next_line(last_line);
    last_line = ft_next_last_line(last_line);
    return (next_line);
}
