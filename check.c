/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:07:28 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/01 13:54:09 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_name(char *av, char *fdf)
{
	int		length;
	int		i;

	length = ft_strlen(av);
	if (length <= 4)
	{
		write(2, "Found wrong line lenght, please try another choice...\n", 54);
		exit(1);
	}
	i = length;
	if (av[i - 4] != fdf[0] || av[i - 3] != fdf[1]
		|| av[i - 2] != fdf[2] || av[i - 1] != fdf[3])
	{
		write(2, "Found wrong file name, please try another choice...\n", 52);
		exit(1);
	}
}
