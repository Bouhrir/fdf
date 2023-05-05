/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:16:32 by obouhrir          #+#    #+#             */
/*   Updated: 2023/05/05 18:19:44 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1550
# endif

# ifndef PURPLE
#  define PURPLE 0x8300FF
# endif

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_data
{
	float	xi;
	float	yi;
	int		dx;
	int		dy;
	int		z;
	int		steps;
}	t_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	int		**map;
	t_img	img;
	int		zoom;
	int		x_offset;
	int		y_offset;
}	t_map;

size_t	ft_strlen(char *c);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	lenth(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_join(char *arc, char *buff);
char	**ft_split(char *s, char c);
int		ft_atoi(char	*str);
int		key_hook(int key, t_map *map);
int		handle(void);
void	check_name(char *av, char *fdf);
void	fd_exit(void);
void	my_mlx_pixel_put(t_map *data, int x, int y, int color);
void	put_image(t_map *map);
void	free_arg(char **arg);
void	get_value(char *file, t_map *map);
int		draw_map(t_map *map);
int		mouse_hook(int key, int x, int y, t_map *map);

#endif