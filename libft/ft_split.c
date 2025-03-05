/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:43:06 by algarci5          #+#    #+#             */
/*   Updated: 2024/10/14 18:58:59 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	words;
	size_t	count;

	words = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			words++;
			count = 1;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (words);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(n * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	while (s[i] && (i < n))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	*freematrix(char **matriz, size_t j)
{
	while (j > 0)
	{
		free(matriz[j - 1]);
		j--;
	}
	free(matriz);
	return (NULL);
}

static char	**fillmatrix(const char	*s, char c, char **matriz)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (j < word_count(s, c))
	{
		while ((s[i] == c) && s[i])
			i++;
		start = i;
		while ((s[i] != c) && s[i])
			i++;
		if (start < i)
		{
			matriz[j] = ft_strndup(s + start, i - start);
			if (!matriz[j])
				return (freematrix(matriz, j));
			j++;
		}
	}
	matriz[j] = NULL;
	return (matriz);
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (fillmatrix(s, c, str));
}
