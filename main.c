/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarci5 <algarci5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:30:02 by algarci5          #+#    #+#             */
/*   Updated: 2025/04/11 20:40:40 by algarci5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 256
#define HEIGHT 256

void open_game()
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	mlx_loop(mlx);
}