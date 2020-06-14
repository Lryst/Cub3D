/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 01:10:25 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 02:23:28 by lryst            ###   ########.fr       */
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
# include "ressources/minilibx-linux/mlx.h"

typedef struct
{
	int			nbr;
	int			**pos_sprite;
	double		y;
	double		x;
	double		indet;
	double		transx;
	double		transy;
	int			screenx;
	int			height;
	int			width;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	int			texx;
	int			texy;
}				t_sprite;

typedef struct
{
	int			width;
	int			height;
	int			error;
	char		**line;
	t_sprite	sprite;
}				t_map;

typedef struct
{
	int			red;
	int			green;
	int			blue;
	int			color;
}				t_color;

typedef struct	s_texture
{
	void		*texture;
	void		*adr;
	char		*path;
	int			*iadr;
	int			**tab_adr;
	int			width;
	int			height;
	int			size_line;
	int			endian;
	int			bits_per_pixel;
	int			texx;
	int			texy;
	double		texpos;
}				t_texture;

typedef struct
{
	int			forward;
	int			backward;
	int			turnleft;
	int			turnright;
	int			rightward;
	int			leftward;
}				t_move;

typedef	struct
{
	int			x;
	int			y;
	int			texx;
	int			texy;
	double		texpos;
	double		wallx;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapy;
	int			mapx;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	double		step;
	int			hit;
	int			side;
	double		frametime;
	double		movespeed;
	double		rotspeed;
	double		olddirx;
	double		oldplanex;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	int			*s_order;
	double		*s_dist;
	double		*zbuffer;
}				t_player;

typedef	struct
{
	int			width;
	int			height;
	int			posx;
	int			posy;
	int			map_height;
	int			map_width;
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	t_texture	s;
	t_color		f;
	t_color		c;
	t_map		map;
	char		**closed_map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	int			*img_iadr;
	void		*img_ptr;
	int			size_line;
	int			endian;
	int			bits_per_pixel;
	t_player	player;
	t_move		move;
	int			*tab_textures[5];
	char		orientation;
	char		*line;
	char		**tab;
	char		*tmp;
	int			count;
	int			esc;
	int			save;
}				t_cub3d;

typedef struct
{
	int			width;
	int			height;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
	int			map;
	int			position;
	int			posx;
	int			posy;
	int			count;
}				t_check_struct;

int				check_is_tab_num(char **tab);
void			put_color_in_struct(int *tex_color, char **color);
void			separate_color_f(char **tab, t_cub3d *cub, t_check_struct *ret);
void			separate_color_c(char **tab, t_cub3d *cub, t_check_struct *ret);

void			check_bad_line(char **tab, int i);
int				ft_strsame(char *s1, char *s2);
int				check_position(t_check_struct *ret, t_cub3d *cub);

void			free_double_tab(char **str);
void			free_tex(t_texture *tex);
void			free_void(void *cub);
void			ft_error(char *str);
int				close_prog(t_cub3d *cub);

void			get_position_sprite(t_cub3d *cub);
void			check_nbr_of_sprite(t_cub3d *cub);

void			init_check_struct(t_check_struct *ret);
void			init_cub3d(t_cub3d *cub);
int				check_struct(t_check_struct *ret);

void			init_direction2(t_cub3d *cub);
void			init_direction(t_cub3d *cub);
void			init_position(t_player *player, t_cub3d *cub);

void			check_screen_size(t_cub3d *cub);
int				check_is_ptcub(char *av, char *file);
void			check_args(t_cub3d *cub, int ac, char **av, int fd);

int				main(int ac, char **av);

int				key_pressed(int key, t_cub3d *cub);
int				key_release(int key, t_cub3d *cub);
int				print_screen(t_cub3d *cub);
void			mlx_handle(t_cub3d *cub, char *av);

void			move(t_cub3d *cub);
void			forward(t_cub3d *cub);
void			backward(t_cub3d *cub);
void			rightward(t_cub3d *cub);
void			leftward(t_cub3d *cub);

void			init_cub3d(t_cub3d *cub);
void			check_map(char *str, t_cub3d *cub, int count);
int				check_closed_map(t_cub3d *c);
int				parcour_closed_map(char **map, int j, int i, int height);
void			check_nbr_of_sprite(t_cub3d *cub);
void			get_position_sprite(t_cub3d*cub);

void			parse_line_2(t_cub3d *cub, t_check_struct *ret, int i);
void			parse_line(t_cub3d *cub, t_check_struct *ret);
void			parse_3(t_cub3d *cub, t_check_struct *ret);
void			parse_2(t_cub3d *cub, t_check_struct *ret);
void			start_parsing(int fd, t_cub3d *cub);

void			draw_plan(t_cub3d *cub, t_player *player);
void			draw_sprite(t_cub3d *cub, t_player *player, double *zbuffer);

void			check_wall_hit_2(t_cub3d*cub, t_player *player);
void			check_wall_hit(t_cub3d *cub, t_player *player);
void			get_side_dist(t_cub3d *cub, t_player *player);
void			init_raycasting(t_cub3d *cub, t_player *player);
void			start_ray_casting(t_cub3d *cub, t_player *player);

int				check_line_is_num(char *str);
void			separate_r(char **tab, t_cub3d *cub, t_check_struct *ret);

void			turnright(t_cub3d *cub);
void			turnright2(t_cub3d *cub);
void			turnleft(t_cub3d *cub);
void			turnleft2(t_cub3d *cub);

void			save(t_cub3d *cub);

int				check_map_space(char **map, int j, int i);
int				parcour_closed_map(char **map, int j, int i, int height);
int				check_closed_map(t_cub3d *cub);
void			check_map(char *str, t_cub3d *cub, int count);

void			separate_texture_no(char **tab, t_cub3d *cub,
t_check_struct *ret);
void			separate_texture_so(char **tab, t_cub3d *cub,
t_check_struct *ret);
void			separate_texture_we(char **tab, t_cub3d *cub,
t_check_struct *ret);
void			separate_texture_ea(char **tab, t_cub3d *cub,
t_check_struct *ret);
void			separate_texture_s(char **tab, t_cub3d *cub,
t_check_struct *ret);

void			check_dist_sprite(t_cub3d *cub, t_player *player);
void			sort_sprite(t_cub3d*cub, t_player *player);
void			init_sprite(t_cub3d *cub, t_player *player);
void			init_sprite_2(t_cub3d *cub);
void			gestion_sprite(t_cub3d *cub, t_player *player, double *zbuffer);

void			get_inf(t_cub3d *cub, t_texture *tex, void *mlx_ptr, int **tab);
void			set_img(t_cub3d *cub);

void			side_0(t_cub3d *cub, t_player *player);
void			side_1(t_cub3d *cub, t_player *player);
void			side_2(t_cub3d *cub, t_player *player);
void			side_3(t_cub3d *cub, t_player *player);

#endif
