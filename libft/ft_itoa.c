/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:22:58 by algarci5          #+#    #+#             */
/*   Updated: 2024/10/03 20:26:09 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	size;
	long	aux;
	char	*str;

	size = ft_nlen(n);
	aux = n;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (aux == 0)
		str[0] = '0';
	if (aux < 0)
	{
		str[0] = '-';
		aux = -aux;
	}
	str[size] = '\0';
	while (aux != 0)
	{
		--size;
		str[size] = (aux % 10) + '0';
		aux /= 10;
	}
	return (str);
}
