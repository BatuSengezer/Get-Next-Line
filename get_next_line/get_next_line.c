/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:36:33 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/27 16:36:37 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line(char *remaining_text)
{
    char *current_line;
    int i;
    int j;

    i = 0;
    if (!remaining_text)
        return (NULL);
    while (remaining_text[i] && remaining_text[i] != '\n')
        i++;
    // free at some point
    current_line = (char *)malloc(i + 2);
    j = 0;
    while (i != j)
    {
    current_line[j] = remaining_text[j];
    j++;
    }
    if (remaining_text[i] == '\n')
    {
        current_line[i] = '\n';
        current_line[i + 1] = '\0';
    }
    current_line[i] = '\0';
    return (current_line);
}
char *ft_update_remaining(char *remaining_text, char *current_line)
{
    char *updated_remaining;
    int i;

    i = 0;
    //free at some point
    updated_remaining =(char *)malloc(ft_strlen(remaining_text) - ft_strlen(current_line) + 1);
    if (!updated_remaining)
        return (NULL);
    while (updated_remaining && remaining_text)
    {
        updated_remaining[i] = remaining_text[i + ft_strlen(current_line)];
        i++;
    }
    return (updated_remaining);
}

char *ft_read_file(int fd, char *remaining_text)
{
    char *buffer;
    int read_bytes;

    read_bytes = 1;
    //free later
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (!ft_strchr(remaining_text, '\n'))
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if(read_bytes == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[read_bytes] = '\0';
        remaining_text = ft_strjoin(remaining_text, buffer);
    }
    free(buffer);
    return(remaining_text);
}

char *get_next_line(int fd)
{
    static char *remaining_text;
    char *current_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    remaining_text = ft_read_file(fd, remaining_text);
    current_line = ft_get_line(remaining_text);
    remaining_text = ft_update_remaining(remaining_text, current_line);
    return(current_line);
}

int main(void)
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    get_next_line(fd);
    //close(fd);
}