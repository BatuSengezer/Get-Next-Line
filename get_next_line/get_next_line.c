/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:36:33 by bsengeze          #+#    #+#             */
/*   Updated: 2023/04/05 01:55:59 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *rem_txt)
{
	char	*curr_line;
	int		i;
	
	i = 0;
	if (!*rem_txt)
		return (NULL);
	while (rem_txt[i] && rem_txt[i] != '\n')
		i++;
	curr_line = (char *)malloc(i + 2);
    if(!curr_line)
        return (NULL);
    i = 0;
	while (rem_txt[i] && rem_txt[i] != '\n')
	{
		curr_line[i] = rem_txt[i];
		i++;
	}
	if (rem_txt[i] == '\n')
	{
		curr_line[i] = '\n';
		curr_line[i + 1] = '\0';
	}
	else
		curr_line[i] = '\0';
	return (curr_line);
}

char	*ft_update_remaining(char *rem_txt)
{
	char	*updated_remaining;
	int		i;
	int		j;
    
	i = 0;
    j = 0;
    if (!rem_txt)
        return (NULL);
	while (rem_txt[i] && rem_txt[i] != '\n')
		i++;
	if (!rem_txt[i])
	{
		free(rem_txt);
		return (NULL);
	}
	updated_remaining = (char *)malloc(ft_strlen(rem_txt) - i + 1);
	if (!updated_remaining)
		return (NULL);
    i++;
	while (rem_txt[i])
		updated_remaining[j++] = rem_txt[i++];
	updated_remaining[j] = '\0';
	free(rem_txt);
	return (updated_remaining);

}

char	*ft_read_file(int fd, char *rem_txt)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(rem_txt, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		rem_txt = ft_strjoin(rem_txt, buffer);
	}
	free(buffer);
	return (rem_txt);
}

char	*get_next_line(int fd)
{
	static char	*rem_txt;
	char		*curr_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem_txt = ft_read_file(fd, rem_txt);
	if (!rem_txt)
		return (NULL);
	curr_line = ft_get_line(rem_txt);
    rem_txt = ft_update_remaining(rem_txt);
	return (curr_line);
}
//edit mains with 42 folder before deleting it 
// int main(void)
// {
//     int fd;

//     fd = open("test.txt", O_RDONLY);
//     get_next_line(fd);
//     //close(fd);
// }

// int main(void)
// {
//     int fd;

//     fd = open("empty.txt", O_RDONLY);
//     get_next_line(fd);
//     //close(fd);
// }
