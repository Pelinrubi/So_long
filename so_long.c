/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:54:03 by algarci5          #+#    #+#             */
/*   Updated: 2025/04/08 15:36:20 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_map(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	print_map(char **mapa, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        if (mapa[i] != NULL)  // Check if the row is not NULL
        {
            printf("%s", mapa[i]);  // Print the line followed by a newline
        }
    }
}

int check_map(char **mapa, char *line, int fd)
{
	int		i;
	int		j;
	
	i = 0;
	while (line)
	{
		mapa[i] = ft_calloc(ft_strlen(line), sizeof(char *));
		j = 0;
		while (line[j])
		{
			if (line[j] != '0' && line[j] != '1' && line[j] != 'P' 
				&& line[j] != 'E' && line[j] != 'C' && line[j] != '\n')
			{
				ft_printf("Error: Caracter no válido en el mapa\n");
				exit(0);
			}
			else
				mapa[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}
void mem_errors(char **mapa, int fd, char *line)
{
	if (fd == -1)
	{
		ft_printf("Error: No se pudo abrir el archivo\n");
		exit(0);
	}
	if (!line)
	{
		ft_printf("Error: El mapa esta vacio\n");
		exit(0);
	}
	if (!mapa)
	{
		ft_printf("Error: No se pudo asignar memoria para el mapa\n");
		exit(0);
	}
}

int	main(void)
{
	int		i;
	int		fd;
	char	*line;
	char	**mapa;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	mapa = ft_calloc(ft_strlen(line), sizeof(char *));
	mem_errors(mapa, fd, line);
	i = check_map(mapa, line, fd);
	check_border(mapa);
	map_len(mapa, i);
	map_chars(mapa, i);
	print_map(mapa, i);
	close(fd);
	free_map(mapa);
}
