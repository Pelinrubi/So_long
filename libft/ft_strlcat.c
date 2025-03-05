/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:38:29 by algarci5          #+#    #+#             */
/*   Updated: 2024/10/03 19:23:36 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size < (len_dest + 1))
		return (size + len_src);
	while (src[i] != '\0' && (len_dest + i) < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
/*int	main(void)
{
	// char	src[] = "mundo";
	// char	dest[30] = "Hola ";
// 
	// ft_strlcat(dest, src, 10);
	// printf("%d", dest);
	// char *str1[10] = "hola";
	// ft_strlcat("pqrs", "abcdefghi", 11);
}*/