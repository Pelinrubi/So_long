/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:46:15 by algarci5          #+#    #+#             */
/*   Updated: 2025/03/03 15:56:09 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_copy(char *dest, const char *src, size_t *i)
{
	size_t	j;

	j = 0;
	while (src[j])
		dest[(*i)++] = src[j++];
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s1)
		s1 = ft_calloc_gnl(1, sizeof(char));
	if (!s2)
		s2 = ft_calloc_gnl(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!result)
	{
		free(s1);
		free((char *)s2);
		return (NULL);
	}
	ft_copy(result, s1, &i);
	ft_copy(result, s2, &i);
	result[i] = '\0';
	free(s1);
	return (result);
}

void	ft_memset_gnl(void *ptr, int value, size_t num)
{
	unsigned char	*p;

	p = ptr;
	while (num--)
		*p++ = (unsigned char)value;
}
