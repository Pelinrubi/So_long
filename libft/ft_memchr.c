/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:30:54 by algarci5          #+#    #+#             */
/*   Updated: 2024/09/26 16:47:51 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = (const unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
/*int main() {
    char str[] = "Hello, World!";
    char *result = ft_memchr(str, 'W', 13);

    if (result != NULL) {
        printf("Encontrado: %c\n", *result);
    } else {
        printf("No encontrado\n");
    }

    return 0;
}*/