/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:46:20 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/05 18:42:35 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1920, 1080, "FDF");
	map->img.img = mlx_new_image(map->mlx, 1920, 1080);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
			&map->img.line_length, &map->img.endian);
	map->zoom = 0;
	map->x_offset = 0;
	map->y_offset = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		write(2, "Please enter 2 agement!!!\n", 26);
		exit(0);
	}
	else
	{
		check_name(av[1], ".fdf");
		get_value(av[1], &map);
		ft_init(&map);
		mlx_loop_hook(map.mlx, &draw_map, &map);
		mlx_hook(map.win, 2, 0, key_hook, &map);
		mlx_mouse_hook(map.win, mouse_hook, &map);
		mlx_hook(map.win, 17, 0, handle, NULL);
		mlx_loop(map.mlx);
	}
}
