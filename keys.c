/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:43:28 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/05 18:43:45 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*------------mouse-------------------*/
int	mouse_hook(int key, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	if (key == 4)
		map->zoom += 2;
	if (key == 5)
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
	if (key == 123)
		map->x_offset -= 5;
	if (key == 124)
		map->x_offset += 5;
	if (key == 125)
		map->y_offset += 5;
	if (key == 126)
		map->y_offset -= 5;
	return (0);
}

/*------------handle-------------------*/
int	handle(void)
{
	exit(0);
}
