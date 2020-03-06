/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:52 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 21:40:01 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_player *p, t_cub3d *q)
{
	
    p->posx = (double)q->posx;
    p->posy = (double)q->posy;
    p->planex = 0;
    p->planey = 0.66;
	p->time = 0;
	p->oldtime = 0;
	p->dirx = -1;
	p->diry = 0;
}

int key_pressed(int key, t_cub3d *ptr)
{
    ft_printf("%d\n", key);
	
	key == 13 ? ptr->move.forward = 1 : 0;
	key == 1 ? ptr->move.backward = 1 : 0;
	key == 2 ? ptr->move.turnright = 1 : 0;
	key == 0 ? ptr->move.turnleft = 1 : 0;
    return (0);
}

int key_release(int key, t_cub3d *ptr)
{
	key == 13 ? ptr->move.forward = 0 : 0;
	key == 1 ? ptr->move.backward = 0 : 0;
	key == 2 ? ptr->move.turnright = 0 : 0;
	key == 0 ? ptr->move.turnleft = 0 : 0;
	return (0);
}

int		print_screen(t_cub3d *ptr)
{
	ray_caster(ptr, &ptr->p);
	ptr->move.turnright ? turnRight(ptr) : 0;
	ptr->move.turnleft ? turnLeft(ptr) : 0;
	ptr->move.forward ? forward(ptr) : 0;
	ptr->move.backward ? backward(ptr) : 0;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img, 0, 0);
	return (1);
}

void	mlx_handle(t_cub3d *ptr, char *av)
{
    ptr->mlx_ptr = mlx_init();
    ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->width, ptr->height, av);
    ptr->img = mlx_new_image(ptr->mlx_ptr, ptr->width, ptr->height);
    ptr->img_ptr = mlx_get_data_addr(ptr->img, &ptr->bpp, &ptr->sl, &ptr->endian);
	//mlx_key_hook(ptr->win_ptr, key_pressed, ptr);

	mlx_hook(ptr->win_ptr, 2, 0, key_pressed, ptr);
	mlx_hook(ptr->win_ptr, 3, 0, key_release, ptr);
	mlx_loop_hook(ptr->mlx_ptr, &print_screen, ptr);
    mlx_loop(ptr->mlx_ptr);
}

int main(int ac, char **av)
{
	t_cub3d ptr;
	
	if (ac != 2)
		return (0);
	parsing(open(av[1], O_RDONLY), &ptr);
	init_player(&ptr.p, &ptr);
	mlx_handle(&ptr, av[1]);
	//printf("%d\n", atoi("223,45,0"));
	//system("leaks a.out");
}