/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:34:27 by algarci5          #+#    #+#             */
/*   Updated: 2025/03/19 17:07:25 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_border(char **mapa)
{
	size_t	j;
	size_t	i;
	size_t	colum;

	j = 0;
	i = 0;
	colum = ft_strlen(mapa[0]) - 1;
	while (mapa[i] != NULL)
	{
		if (mapa[i][0] != '1' || mapa[i][colum - 1] != '1')
		{
			ft_printf("Error: bordes invalidos lados\n");
			exit(0);
		}
		i++;
	}
	while (mapa[0][j] != '\n')
	{
		if (mapa[0][j] != '1' || mapa[i - 1][j] != '1')
		{
			ft_printf("Error: bordes invalidos arriba/abajo\n");
			exit(0);
		}
		j++;
	}
}
void	check_chars(int c, int p, int e)
{
	if (c < 1 || p != 1 || e != 1)
	{
		ft_printf("Error: Faltan/sobran characteres\n");
		exit(0);
	}
}

void	map_chars(char **mapa, int i)
{
	int	j;
	int	c;
	int	p;
	int	e;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (mapa[i])
	{
		j = 0;
		while (mapa[i][j])
		{
			if (mapa[i][j] == 'C')
				c++;
			else if (mapa[i][j] == 'P')
				p++;
			else if (mapa[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	check_chars(c, p, e);
}

void	map_len(char **mapa, int rows)
{
	int	j;

	j = 0;
	while (j < rows)
	{
		if (j == (rows - 1))
		{
			if (ft_strlen(mapa[j]) + 1 != ft_strlen(mapa[0]))
			{
				ft_printf("Error: Mapa invalido\n");
				exit(0);
			}
		}
		else if (ft_strlen(mapa[j]) != ft_strlen(mapa[0]))
		{
			ft_printf("Error: Mapa invalido\n");
			exit(0);
		}
		j++;
	}
}
