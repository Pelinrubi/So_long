/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:54:03 by algarci5          #+#    #+#             */
/*   Updated: 2025/03/05 19:28:38 by algarci5         ###   ########.fr       */
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
	print_map(mapa, i);
}
