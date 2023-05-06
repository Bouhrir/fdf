/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:44:36 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/06 14:51:11 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*------------put_pixel-------------------*/
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

/*------------strlen-------------------*/
size_t	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

/*------------swap-------------------*/
void	swap_points(t_point *p1, t_point *p2)
{
	t_point	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
