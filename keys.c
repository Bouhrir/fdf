/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:43:28 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/10 17:58:51 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*------------mouse-------------------*/
int	mouse_hook(int key, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	if (key == IN)
		map->zoom += 1;
	if (key == OUT)
		map->zoom -= 1;
	return (1);
}
/*------------key-------------------*/

void	fd_exit(void)
{
	write(2, "No file here\n", 13);
	exit(1);
}

/*------------key-------------------*/
int	key_hook(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_image(map->mlx, map->img.img);
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	if (key == UP)
		map->y_offset -= 5;
	if (key == DOWN)
		map->y_offset += 5;
	if (key == RIGHT)
		map->x_offset += 5;
	if (key == LEFT)
		map->x_offset -= 5;
	return (0);
}

/*------------handle-------------------*/
int	handle(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img.img);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}
