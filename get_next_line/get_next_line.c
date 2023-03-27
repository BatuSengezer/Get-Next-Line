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

char *ft_line(int fd, char *remaining_text)
{

}
char *ft_update_remaining(char *remaining_text)
{

}

char *ft_read_remaining(int fd, char *remaining_text)
{

}

char *get_next_line(int fd)
{
static char *remaining_text;
char *current_line;

remaining_text = ft_read_remaining(fd, remaining_text);

    return(current_line);
}
