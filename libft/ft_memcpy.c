/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:58:39 by algarci5          #+#    #+#             */
/*   Updated: 2024/09/28 14:04:43 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				size;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	size = 0;
	if (!dest && !src)
		return (NULL);
	while (size < n)
	{
		d[size] = s[size];
		size++;
	}
	return (dest);
}
/*int main(void)
{
    char src[] = "Hello, World!";
    char dest[20];

    ft_memcpy(dest, src, 4);
    printf("Destino: %s\n", dest);

    return 0;
}*/