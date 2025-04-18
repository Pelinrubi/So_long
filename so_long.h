/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:09:23 by algarci5          #+#    #+#             */
/*   Updated: 2025/04/11 20:44:11 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

void mem_errors(char **mapa, int fd, char *line);
int check_map(char **mapa, char *line, int fd);
void	map_len(char **mapa, int rows);
void	map_chars(char **mapa, int i);
void	check_chars(int c, int p, int e);
void	check_border(char **mapa);
char	*free_map(char **map);
char	**clone_map(char **map);
char	*check_extension(char *arg);
void open_game(void);

typedef struct s_vars
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
} t_vars;

#endif