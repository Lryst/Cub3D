/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:38:04 by lryst             #+#    #+#             */
/*   Updated: 2020/02/17 18:55:50 by lryst            ###   ########.fr       */
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
	int mapx;
	int mapy;
}        		t_cub3d;


void	parsing(int fd);
void	separate_r(char **tab, t_cub3d *ptr);
void	parse_line(char *line, t_cub3d *ptr);
void	init_cub3d(t_cub3d *ptr);


#endif