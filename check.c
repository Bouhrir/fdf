/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:07:28 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/08 18:54:15 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_name(char *av, char *fdf)
{
	int		i;

	i = ft_strlen(av);
	if (i <= 4 || av[i - 4] != fdf[0] || av[i - 3] != fdf[1]
		|| av[i - 2] != fdf[2] || av[i - 1] != fdf[3])
	{
		write(2, "error: please try another choice...\n", 36);
		exit(1);
	}
}

void	g_exit(void)
{
	write(1, "Empty file\n", 12);
	exit(0);
}
