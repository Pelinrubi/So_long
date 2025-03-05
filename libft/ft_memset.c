/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:05:56 by algarci5          #+#    #+#             */
/*   Updated: 2024/09/26 14:44:18 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				size;
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	size = 0;
	while (size < n)
	{
		ptr[size] = (unsigned char)c;
		size++;
	}
	return (s);
}
