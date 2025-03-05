/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:08:38 by algarci5          #+#    #+#             */
/*   Updated: 2025/02/07 18:16:20 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_u(n / 10);
	num = n % 10 + '0';
	count += ft_putchar(num);
	return (count);
}
