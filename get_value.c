/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:29:36 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/08 22:35:43 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	map_len(char **area)
{
	int	i;

	i = 0;
	while (area[i])
		i++;
	return (i);
}

void	wrong_line(char **splited)
{
	int	len;
	int	i;
	int	x;

	i = 0;
	x = 1;
	len = ft_strlen(splited[0]);
	while (splited[x])
	{
		i = ft_strlen(splited[x]);
		if (i < len)
		{
			write(2, "Found wrong line length. Exiting.\n", 34);
			exit(1);
		}
		x++;
	}	
}

void	check_line(char **splited, t_map *map)
{
	int	x;
	int	i;

	x = 0;
	i = map->height;
	while (i > 0)
	{
		if (splited[i - 1] == NULL)
			x++;
		i--;
	}
	if (i != x)
	{
		write(2, "Wrong lines\n", 12);
		exit(1);
	}
	wrong_line(splited);
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
	if (line == NULL)
		g_exit();
	map->height = 0;
	while (line)
	{
		area = ft_join(area, line);
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	close_free(fd, line);
	splited = ft_split(area, '\n');
	check_line(splited, map);
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
