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

void	init_position(t_cub3d *ptr)
{
	double rotSpeed;

	rotSpeed = 1.5706;
	if (ptr->orientation == 'W')
	{
		ptr->player.dirX = 0.0;
		ptr->player.dirY = -1.0;
		ptr->player.oldplaneX = ptr->player.planeX;
		ptr->player.planeX = ptr->player.planeX * cos(rotSpeed) - ptr->player.planeY * sin(rotSpeed);
		ptr->player.planeY = ptr->player.oldplaneX * sin(rotSpeed) + ptr->player.planeY * cos(rotSpeed);
	}
	if (ptr->orientation == 'E')
	{
		ptr->player.dirX = 0.0;
		ptr->player.dirY = 1.0;
		ptr->player.oldplaneX = ptr->player.planeX;
		ptr->player.planeX = ptr->player.planeX * cos(rotSpeed) - ptr->player.planeY * sin(rotSpeed);
		ptr->player.planeY = ptr->player.oldplaneX * sin(rotSpeed) + ptr->player.planeY * cos(rotSpeed);
	}

}

void	check_screen_size(t_cub3d *cub)
{
	int height;
	int width;

	height = cub->height;
	width = cub->width;
	mlx_get_screen_size(cub->mlx_ptr, &width, &height);
	width < cub->width ? cub->width = width : 0;
	height < cub->height ? cub->height = height : 0;
}

void	init_player(t_player *player, t_cub3d *cub)
{
	//check_screen_size(cub);
	player->posX = (double)cub->posX + 0.5;
	player->posY = (double)cub->posY + 0.5;
	player->planeX = 0.0;
	player->planeY = 0.66;
	player->time = 0.0;
	player->oldtime = 0.0;
	if (cub->orientation == 'S')
	{
		player->dirX = 1.0;
		player->dirY = 0.0;
	}
	player->dirX = -1.0;
	player->dirY = 0.0;
}

int key_pressed(int key, t_cub3d *cub)
{
	printf("key pressed [%d]\n", key);
	key == 53 ?cub->esc = 1 : 0;
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
	//printf("key [%d]\n", key);
	key == 53 ? cub->esc = 0 : 0;
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
	cub->img_ptr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->size_line, &cub->endian);
	cub->img_iadr = (int*)cub->img_ptr;
	start_ray_casting(cub, &cub->player);
	move(cub);
	if (!(mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0)))
		ft_error("mlx_put_image_to_window PAS POSSIBLE !\n");
	mlx_destroy_image(cub->mlx_ptr, cub->img);
	return (1);
}

void	mlx_handle(t_cub3d *cub, char *av)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		ft_error("mlx_ptr == NULL, alos quil a etait initié");
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->width, cub->height, av);
	set_img(cub);
	if (cub->mlx_ptr == NULL || cub->win_ptr == NULL)
		ft_error("mlx_ptr == NULL, alos quil a etait initié");
	if (cub->save == 1)
		print_screen(cub);
	mlx_hook(cub->win_ptr, 2, 0, key_pressed, cub);
	mlx_hook(cub->win_ptr, 3, 0, key_release, cub);
	mlx_hook(cub->win_ptr, 17, 1L << 17, close_prog, cub);
	mlx_loop_hook(cub->mlx_ptr, &print_screen, cub);
	mlx_loop(cub->mlx_ptr);
}

int main(int ac, char **av)
{
	t_cub3d cub;

	init_cub3d(&cub);
	cub.save = 0;
	ft_printf("\n\n--->	START	<---\n\n");
	if (ac == 2)
	{
		start_parsing(open(av[1], O_RDONLY), &cub);
		init_player(&cub.player, &cub);
		init_position(&cub);
		mlx_handle(&cub, av[1]);
	}
	if (ac == 3 && ft_strcmp("--save", av[2]) == 0)
	{
		cub.save = 1;
		start_parsing(open(av[1], O_RDONLY), &cub);
		init_player(&cub.player, &cub);
		init_position(&cub);
		mlx_handle(&cub, av[1]);
	}
	ft_error("bad arguments");
}

