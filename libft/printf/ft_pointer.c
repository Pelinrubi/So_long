/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:07:44 by algarci5          #+#    #+#             */
/*   Updated: 2025/02/07 18:48:50 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(size_t num, char *s)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(num, s);
	return (count);
}
