/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:20:11 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/05 18:25:37 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = data->img.addr + (y * data->img.line_length + x
				* (data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// void	put_image(t_map *map)
// {
// 	mlx_key_hook(map->win, key_hook, &map);
// 	mlx_mouse_hook(map->win, mouse_hook, &map);
// 	mlx_hook(map->win, 17, 0, handle, NULL);
// }
