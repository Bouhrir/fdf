/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:12:33 by obouhrir          #+#    #+#             */
/*   Updated: 2023/04/13 03:00:41 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (len > lenth(s))
		len = lenth(s) - start;
	if (start >= lenth(s))
		return (ft_strdup("\0"));
	i = 0;
	while (len)
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

size_t	lenth(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*p;

	if (!s1)
		return (0);
	i = 0;
	p = malloc(lenth(s1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_join(char *arc, char *buff)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = malloc(lenth(arc) + lenth(buff) + 1);
	if (!p)
		return (NULL);
	while (arc && arc[i])
	{
		p[j++] = arc[i++];
	}
	i = 0;
	while (buff && buff[i])
	{
		p[j++] = buff[i++];
	}
	p[j] = '\0';
	free(arc);
	return (p);
}
