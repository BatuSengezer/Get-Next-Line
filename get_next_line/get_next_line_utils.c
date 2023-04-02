/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:57:57 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/25 18:57:59 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*mal;
	char	*cs1;
	char	*cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	j = 0;
	mal = malloc(sizeof(char) * (ft_strlen(cs1) + ft_strlen(cs2)) + 1);
	if (!mal)
		return (0);
	i = 0;
	while (ft_strlen(cs1) > i)
	{
		mal[i] = cs1[i];
		i++;
	}
	while (ft_strlen(cs2) > j)
	{
		mal[i + j] = cs2[j];
		j++;
	}
	mal[i + j] = 0;
	return (mal);
}

