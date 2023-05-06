/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:43:28 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/05 22:38:33 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*------------mouse-------------------*/
int	mouse_hook(int key, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	if (key == IN)
		map->zoom += 2;
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
		exit(0);
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
int	handle(void)
{
	exit(0);
}
