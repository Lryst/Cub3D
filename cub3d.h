/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:38:04 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 15:40:15 by lryst            ###   ########.fr       */
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
# include "mlx.h"
//# include "ressources/minilibx/mlx.h"

typedef struct
{
	int width;
	int height;
	int error;
	char **line;
}				t_map;

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
	int posx;
	int posy;
	int map_height;
	int map_width;
	t_texture no;
	t_texture so;
	t_texture we;
	t_texture ea;
	t_texture s;
	t_color f;
	t_color c;
	t_map map;
	char **closed_map;
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
	int position;
	int posx;
	int posy;
}				t_check_struct;

void	separate_color_f(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_color_c(char **tab, t_cub3d *ptr, t_check_struct *ret);


void	init_cub3d(t_cub3d *ptr);
void	check_map(char *str, t_cub3d *ptr, int count);
void	parse_line(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	parsing(int fd);

void	separate_r(char **tab, t_cub3d *ptr, t_check_struct *ret);

void	separate_texture_no(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_so(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_we(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_ea(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_s(char **tab, t_cub3d *ptr, t_check_struct *ret);

void	init_check_struct(t_check_struct *ret);
void	init_cub3d(t_cub3d *ptr);
int		check_struct(t_check_struct *ret);

#endif