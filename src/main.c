/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:52 by lryst             #+#    #+#             */
/*   Updated: 2020/03/10 15:23:49 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_player *p, t_cub3d *q)
{
	
    p->posX = (double)q->posX;
    p->posY = (double)q->posY;
    p->planeX = 0;
    p->planeY = 0.66;
	p->time = 0;
	p->oldtime = 0;
	p->dirX = -1;
	p->dirY = 0;
}

int key_pressed(int key, t_cub3d *cub)
{
    ft_printf("%d\n", key);
	
	key == 13 ? cub->move.forward = 1 : 0;
	key == 1 ? cub->move.backward = 1 : 0;
	key == 124 ? cub->move.turnright = 1 : 0;
	key == 123 ? cub->move.turnleft = 1 : 0;
	key == 2 ? cub->move.rightward = 1 : 0;
	key == 0 ? cub->move.leftward = 1 : 0;
    return (0);
}

int key_release(int key, t_cub3d *cub)
{
	key == 13 ? cub->move.forward = 0 : 0;
	key == 1 ? cub->move.backward = 0 : 0;
	key == 124 ? cub->move.turnright = 0 : 0;
	key == 123 ? cub->move.turnleft = 0 : 0;
	key == 2 ? cub->move.rightward = 0 : 0;
	key == 0 ? cub->move.leftward = 0 : 0;
	return (0);
}

int		print_screen(t_cub3d *cub)
{
	cub->img = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	cub->img_ptr = mlx_get_data_addr(cub->img, &cub->bpp, &cub->sl, &cub->endian);
	ray_caster(cub, &cub->player);
	//printf("coucou 13\n");
	cub->move.turnright ? turnRight(cub) : 0;
	cub->move.turnleft ? turnLeft(cub) : 0;
	cub->move.forward ? forward(cub) : 0;
	cub->move.backward ? backward(cub) : 0;
	cub->move.rightward ? rightward(cub) : 0;
	cub->move.leftward ? leftward(cub) : 0;
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	if (cub->img != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->img);
	return (1);
}

void	mlx_handle(t_cub3d *cub, char *av)
{
	printf("coucou 1\n");
    cub->mlx_ptr = mlx_init();
	printf("coucou 2\n");
    cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->width, cub->height, av);
	printf("coucou 3\n");
	set_img(cub);
	//mlx_key_hook(cub->win_ptr, key_pressed, ptr);

	mlx_hook(cub->win_ptr, 2, 0, key_pressed, cub);
	mlx_hook(cub->win_ptr, 3, 0, key_release, cub);
	mlx_loop_hook(cub->mlx_ptr, &print_screen, cub);
    mlx_loop(cub->mlx_ptr);
}

int main(int ac, char **av)
{
	t_cub3d cub;
	
	if (ac != 2)
		return (0);
	parsing(open(av[1], O_RDONLY), &cub);
	init_player(&cub.player, &cub);
	mlx_handle(&cub, av[1]);
	//printf("%d\n", atoi("223,45,0"));
	//system("leaks a.out");
}