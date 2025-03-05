/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:09:16 by algarci5          #+#    #+#             */
/*   Updated: 2025/02/07 18:47:24 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		count;
	size_t	i;

	if (s == NULL)
		return (ft_putstr("(null)"));
	count = 0;
	i = 0;
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
