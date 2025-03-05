/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:20:15 by algarci5          #+#    #+#             */
/*   Updated: 2025/03/03 15:58:24 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_line(char *line, char **extra)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i + j])
	{
		(*extra)[j] = line[i + j];
		line[i + j] = '\0';
		j++;
	}
	(*extra)[j] = '\0';
	return (line);
}

char	*finalize_line(char *line, char **extra)
{
	cut_line(line, extra);
	if (line[0] == '\0')
	{
		if (*extra)
		{
			free(*extra);
			*extra = NULL;
		}
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset_gnl(ptr, 0, total_size);
	return (ptr);
}

char	*free_null(char **buffer, char **extra)
{
	if (*extra)
	{
		free(*extra);
		*extra = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*line;
	char		*buffer;
	int			bytes_read;

	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!extra)
		extra = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (BUFFER_SIZE <= 0 || !extra || !buffer)
		return (free_null(&buffer, &extra));
	line = ft_strjoin_gnl(NULL, extra);
	bytes_read = 1;
	while (!ft_strchr_gnl(buffer, '\n') && bytes_read > 0
		&& !ft_strchr_gnl(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), line = NULL, free_null(&buffer, &extra));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	return (free(buffer), finalize_line(line, &extra));
}
// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	return 0;
// }
