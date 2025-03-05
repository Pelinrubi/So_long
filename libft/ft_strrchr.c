/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:38:00 by algarci5          #+#    #+#             */
/*   Updated: 2024/09/28 14:17:01 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	while (size >= 0)
	{
		if (s[size] == (char)c)
			return ((char *)&s[size]);
		size--;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/*int main()
{
    const char str[] = "Hello, World!";
    char *result = ft_strrchr(str, 's');

    if (result)
        printf("Último encontrado: %c\n", *result);
    else
        printf("No encontrado\n");

    return 0;
}*/