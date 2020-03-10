/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:38:04 by lryst             #+#    #+#             */
/*   Updated: 2020/03/10 15:24:27 by lryst            ###   ########.fr       */
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
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
//# include "ressources/minilibx/mlx.h"

# define ABS(x) (x > 0 ? (x) : (-x))

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
	int forward;
	int backward;
	int turnleft;
	int turnright;
	int rightward;
	int leftward;
} 	t_move;


typedef	struct 
{
	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	double time;
	double oldtime;
	double camerax;
	double rayDirx;
	double rayDiry;
	int mapy;
	int mapx;
	double sideDistx;
    double sideDisty;
	double deltaDistx;
	double deltaDisty;
	double perpWallDist;
	int stepx;
	int stepy;
	int hit;
	int side;
	double frametime;
	double movespeed;
	double rotspeed;
	double oldDirx;
	double oldplanex;
	int	lineHeight;
	int drawStart;
	int drawEnd;
	int color;
}				t_player;

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
	void *mlx_ptr;
	void *win_ptr;
	void *img;
	void *img_ptr;
	int sl;
	int endian;
	int bpp;
	t_player p;
	t_move move;
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
	int count;
}				t_check_struct;

void	separate_color_f(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_color_c(char **tab, t_cub3d *ptr, t_check_struct *ret);


void	init_cub3d(t_cub3d *ptr);
void	check_map(char *str, t_cub3d *ptr, int count);
void	parse_line(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	parsing(int fd, t_cub3d *ptr);

void	separate_r(char **tab, t_cub3d *ptr, t_check_struct *ret);

void	separate_texture_no(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_so(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_we(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_ea(char **tab, t_cub3d *ptr, t_check_struct *ret);
void	separate_texture_s(char **tab, t_cub3d *ptr, t_check_struct *ret);

void	init_check_struct(t_check_struct *ret);
void	init_cub3d(t_cub3d *ptr);
int		check_struct(t_check_struct *ret);

void    ray_caster(t_cub3d *q, t_player *p);
void 	turnRight(t_cub3d *ptr);
void 	turnLeft(t_cub3d *ptr);
void 	forward(t_cub3d *ptr);
void 	backward(t_cub3d *ptr);
void	rightward(t_cub3d *ptr);
void    leftward(t_cub3d *ptr);

#endif