/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:54:03 by algarci5          #+#    #+#             */
/*   Updated: 2025/03/12 20:19:43 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(char **mapa, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        if (mapa[i] != NULL)  // Check if the row is not NULL
        {
            printf("%s", mapa[i]);  // Print the line followed by a newline
        }
    }
}
void check_chars(int c, int p, int e)
{
	if (c < 1 || p != 1 || e != 1)
	{
		ft_printf("Error: Mapa invalido\n");
		exit(0);
	}
}
void map_chars(char** mapa)
{
	int i;
	int j;
	int c;
	int p;
	int e;
	
	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while(mapa[i])
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

void map_len(char** mapa, int rows)
{
	int j;

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

int	main(void)
{
	char	*line;
	char	**mapa;
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	fd = open("map.txt", O_RDONLY);
	line = get_next_line(fd);
	mapa = ft_calloc(ft_strlen(line), sizeof(char *));
	while (line)
	{
		mapa[i] = ft_calloc(ft_strlen(line), sizeof(char));
		while (line[j])
		{
			if(line[j] != '0' && line[j] != '1' && line[j] != 'P' && line[j] != 'E' && line[j] != 'C' && line[j] != '\n')
			{
				ft_printf("Error\n");
				exit(0);
			}
			else
				mapa[i][j] = line[j];
			j++;
		}
		i++;
		j = 0;
		free(line);
		line = get_next_line(fd);
	}
	map_len(mapa, i);
	map_chars(mapa);
	print_map(mapa, i);
}
