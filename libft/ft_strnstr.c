/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:29:26 by algarci5          #+#    #+#             */
/*   Updated: 2024/10/03 18:59:21 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	j = 0;
	if (!l[j])
		return (b);
	while ((b[i] != '\0') && (i < len))
	{
		j = 0;
		while ((b[i + j] == l[j]) && (i + j) < len && b[i + j])
			j++;
		if (l[j] == '\0')
			return (&b[i]);
		i++;
	}
	return (0);
}
/*int	main()
{
	char big[] = "Hola mundo";
	char little[] = "z";

	printf("%s", ft_strnstr(big, little, 20));
}*/