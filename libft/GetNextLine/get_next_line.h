/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:46:13 by algarci5          #+#    #+#             */
/*   Updated: 2025/03/05 18:20:06 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t count, size_t size);
size_t	ft_strlen_gnl(const char *c);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, const char *s2);
void	ft_copy(char *dest, const char *src, size_t *i);
void	ft_memset_gnl(void *ptr, int value, size_t num);

#endif