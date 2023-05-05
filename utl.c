/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:02:56 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/05 18:44:34 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*------------atoi-------------------*/

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

/*------------split-------------------*/
static int	count(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			word++;
		}
	}
	return (word);
}

static long	size(char *s, char c, int i)
{
	int	ct;

	ct = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		ct++;
	}
	return (ct);
}

static void	sp(char *s, char	**res, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = (char *)malloc((size(s, c, i) + 1) * sizeof(char));
			if (!res[j])
				return ;
			while (s[i] && s[i] != c)
			{
				res[j][k++] = s[i++];
			}
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
}

char	**ft_split(char *s, char c)
{
	char	**res;

	res = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	sp(s, res, c);
	return (res);
}
