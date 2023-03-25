#include "get_next_line.h"

char* get_next_line(int fd)
{
    if (!fd || fd < 0)
        return (NULL);
    char* buf = (char*)malloc(100);
    char* tmp = buf;
    int bytes_read;

    while ((bytes_read = read(fd, buf, 1)) > 0)
    {
        if (*buf == '\n' || *buf == EOF)
        {
            break;
        }
        buf++;
    }
    *buf = '\0';
    buf = tmp;
    return buf;
}
/*
int main()
{
    int fd = open("Test123.txt", O_RDONLY);
    puts(get_next_line(fd));
}
*/