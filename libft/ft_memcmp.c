/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:30:20 by algarci5          #+#    #+#             */
/*   Updated: 2024/10/03 18:51:54 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*i;
	const unsigned char		*j;

	i = (const unsigned char *)s1;
	j = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*i != *j)
			return (*i - *j);
		i++;
		j++;
		n--;
	}
	return (0);
}
/*int main()
{
    char s1[] = "Hola";
    char s2[] = "Hol";

    int result = ft_memcmp(s1, s2, 7);
	printf("%d", result);
}*/