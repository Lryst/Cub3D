/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:38:04 by lryst             #+#    #+#             */
/*   Updated: 2020/02/18 17:53:03 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <mlx.h>

typedef struct
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct
{
	char   *path;
	int    **texture;//jai un doute
}               t_texture;

typedef struct
{
	int width;
	int height;
	t_texture no;
	t_texture so;
	t_texture we;
	t_texture ea;
	t_texture s;
	t_color f;
	t_color c;
	char **map;
}        		t_cub3d;

typedef struct
{
	int width;
	int height;
	int no;
	int so;
	int we;
	int ea;
	int s;
	int f;
	int c;
	int map;
}				t_check_struct;

void	separate_color_f(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_color_c(char **tab, t_cub3d *ptr, t_check_struct *ret);


void	init_cub3d(t_cub3d *ptr);
void	check_map(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	parse_line(char *line, t_cub3d *ptr);
void	parsing(int fd);

void	separate_r(char **tab, t_cub3d *ptr, t_check_struct *ret);

void	separate_texture(char **tab, t_cub3d *ptr, t_check_struct *ret);

#endif