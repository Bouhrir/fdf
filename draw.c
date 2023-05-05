/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:30:12 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/05 18:30:44 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point *p, t_map *map)
{
	int	z;
	int	x;
	int	y;

	z = map->map[p->y][p->x - 13];
	x = p->x * (50 + map->zoom);
	y = p->y * (50 + map->zoom);
	p->x = ((x - y) * cos(0.523599));
	p->y = (-z + (x + y) * sin(0.523599));
	p->x += map->x_offset;
	p->y += map->y_offset;
}

void	dda(t_point a, t_point b, t_map *map)
{
	t_data	p;
	float	x;
	float	y;

	isometric(&a, map);
	isometric(&b, map);
	p.dy = b.y - a.y;
	p.dx = b.x - a.x;
	if (abs(p.dy) > abs(p.dx))
		p.steps = abs(p.dy);
	else
		p.steps = abs(p.dx);
	p.yi = p.dy / (float)p.steps;
	p.xi = p.dx / (float)p.steps;
	y = a.y;
	x = a.x;
	while (p.steps)
	{
		my_mlx_pixel_put(map, x, y, PURPLE);
		x += p.xi;
		y += p.yi;
		p.steps--;
	}
}

void	draw_x_y(t_map *map, int x, int y)
{
	t_point	a;
	t_point	b;

	while (x < map->width + 13)
	{
		if (x + 1 < map->width + 13)
		{
			a.x = x;
			a.y = y;
			b.x = x + 1;
			b.y = y;
			dda(a, b, map);
		}
		if (y + 1 < map->height)
		{
			a.x = x;
			a.y = y;
			b.x = x;
			b.y = y + 1;
			dda(a, b, map);
		}
		x++;
	}
}

void	clear_window(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			my_mlx_pixel_put(map, i, j, 0);
			j++;
		}
		i++;
	}
}

int	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	clear_window(map);
	while (y < map->height)
	{
		x = 13;
		draw_x_y(map, x, y);
		y++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}
