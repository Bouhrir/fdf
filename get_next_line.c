/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:08:32 by obouhrir          #+#    #+#             */
/*   Updated: 2023/04/13 03:01:03 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_buff(int fd, char *arc)
{
	char	*buff;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(arc);
			free(buff);
			return (NULL);
		}
		if (i == 0)
			break ;
		buff[i] = '\0';
		arc = ft_join(arc, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (arc);
}

char	*get_befor(char *arc)
{
	char	*line;
	int		i;

	i = 0;
	while (arc[i] && arc[i] != '\n')
		i++;
	if (arc[i] == '\n')
		i++;
	line = ft_substr(arc, 0, i);
	return (line);
}

char	*get_after(char *arc)
{
	char	*new_arc;
	int		i;

	i = 0;
	while (arc[i] && arc[i] != '\n')
		i++;
	if (arc[i] == '\n')
		i++;
	if (arc[i] == 0)
	{
		free(arc);
		return (NULL);
	}
	new_arc = ft_substr(arc, i, lenth(arc) - i);
	free(arc);
	return (new_arc);
}

char	*get_next_line(int fd)
{
	char static	*arc;
	char		*line;

	if (fd == 1 || fd == 2 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	arc = get_buff(fd, arc);
	if (!arc)
		return (NULL);
	line = get_befor(arc);
	arc = get_after(arc);
	return (line);
}
