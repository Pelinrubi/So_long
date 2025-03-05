/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:30:39 by algarci5          #+#    #+#             */
/*   Updated: 2024/10/03 19:45:12 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		s_len;
	size_t		size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if ((start + len) > s_len)
		len = s_len - start;
	sub = (char *)ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	size = 0;
	while (size < len)
	{
		sub[size] = s[start];
		size++;
		start++;
	}
	return (sub);
}
