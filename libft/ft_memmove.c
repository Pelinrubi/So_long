/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:18:29 by algarci5          #+#    #+#             */
/*   Updated: 2024/10/01 18:07:48 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d && (s + n) > d)
	{
		i = n;
		while (i != 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		return (ft_memcpy(d, s, n));
	}
	return (dest);
}
