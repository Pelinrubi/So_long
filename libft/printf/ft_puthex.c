/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:08:20 by algarci5          #+#    #+#             */
/*   Updated: 2025/02/07 19:04:34 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n, char *s)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, s);
	count += ft_putchar(s[n % 16]);
	return (count);
}
