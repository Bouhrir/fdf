/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:29:36 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/03 22:03:02 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_len(char **area)
{
	int	i;

	i = 0;
	while (area[i])
		i++;
	return (i);
}

char	**fill_area(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	*area;
	char	**splited;

	area = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		fd_exit();
	line = get_next_line(fd);
	map->height = 0;
	while (line)
	{
		area = ft_join(area, line);
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	close(fd);
	free(line);
	splited = ft_split(area, '\n');
	free(area);
	return (splited);
}

void	get_value(char	*file, t_map *map)
{
	int		x;
	int		y;
	char	**area;
	char	**splited;

	area = fill_area(file, map);
	map->map = malloc(map->height * sizeof(int *));
	y = 0;
	while (y < map->height)
	{
		splited = ft_split(area[y], ' ');
		map->width = map_len(splited);
		map->map[y] = malloc(map->width * sizeof(int));
		x = 0;
		while (x < map->width)
		{
			map->map[y][x] = ft_atoi(splited[x]);
			x++;
		}
		free_arg(splited);
		y++;
	}
	free_arg(area);
}
