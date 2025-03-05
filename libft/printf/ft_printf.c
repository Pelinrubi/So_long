/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:02:33 by algarci5          #+#    #+#             */
/*   Updated: 2025/02/07 20:58:04 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(char const *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		count += ft_pointer(va_arg(args, size_t), "0123456789abcdef");
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_puthex(va_arg(args, unsigned long long),
				"0123456789abcdef");
	else if (*format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ')
				i++;
			count += ft_convert(&format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
