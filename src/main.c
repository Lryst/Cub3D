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

void	init_direction2(t_cub3d *cub)
{
	if (cub->orientation == 'N')
	{
		cub->player.dirX = -1.0;
		cub->player.dirY = 0.0;
		cub->player.planeX = cub->player.dirY * tan(1.25/2);
		cub->player.planeY = -cub->player.dirX * tan(1.25/2);
	}
	if (cub->orientation == 'S')
	{
		cub->player.dirX = 1.0;
		cub->player.dirY = 0.0;
		cub->player.planeX = -cub->player.dirY * tan(1.25/2);
		cub->player.planeY = -cub->player.dirX * tan(1.25/2);
	}
}

void	init_direction(t_cub3d *cub)
{
	init_direction2(cub);
	if (cub->orientation == 'W')
	{
		cub->player.dirX = 0.0;
		cub->player.dirY = -1.0;
		cub->player.planeX = cub->player.dirY * tan(1.25/2);
		cub->player.planeY = cub->player.dirX * tan(1.25/2);
	}
	if (cub->orientation == 'E')
	{
		cub->player.dirX = 1.0;
		cub->player.dirY = 1.0;
		cub->player.planeX = cub->player.dirY * tan(1.25/2);
		cub->player.planeY = -cub->player.dirX * tan(1.25/2);
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

void	init_position(t_player *player, t_cub3d *cub)
{
	player->posX = (double)cub->posX + 0.5;
	player->posY = (double)cub->posY + 0.5;
	player->planeX = 0.0;
	player->planeY = 0.66;
	player->time = 0.0;
	player->oldtime = 0.0;
	init_direction(cub);
}

int key_pressed(int key, t_cub3d *cub)
{
	key == 65307 ?cub->esc = 1 : 0;
	key == 119 ? cub->move.forward = 1 : 0;
	key == 115 ? cub->move.backward = 1 : 0;
	key == 65363 ? cub->move.turnright = 1 : 0;
	key == 65361 ? cub->move.turnleft = 1 : 0;
	key == 100 ? cub->move.rightward = 1 : 0;
	key == 97 ? cub->move.leftward = 1 : 0;
	return (0);
}

int key_release(int key, t_cub3d *cub)
{
	key == 65307 ? cub->esc = 0 : 0;
	key == 119 ? cub->move.forward = 0 : 0;
	key == 115 ? cub->move.backward = 0 : 0;
	key == 65363 ? cub->move.turnright = 0 : 0;
	key == 65361 ? cub->move.turnleft = 0 : 0;
	key == 100 ? cub->move.rightward = 0 : 0;
	key == 97 ? cub->move.leftward = 0 : 0;
	return (0);
}

int		print_screen(t_cub3d *cub)
{
	cub->img = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	cub->img_ptr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->size_line, &cub->endian);
	cub->img_iadr = (int*)cub->img_ptr;
	start_ray_casting(cub, &cub->player);
	move(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	mlx_destroy_image(cub->mlx_ptr, cub->img);
	return (1);
}

void	mlx_handle(t_cub3d *cub, char *av)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		ft_error("mlx_ptr == NULL, alos quil a etait initié");
	check_screen_size(cub);
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->width, cub->height, av);
	set_img(cub);
	if (cub->mlx_ptr == NULL || cub->win_ptr == NULL)
		ft_error("mlx_ptr == NULL, alos quil a etait initié");
	if (cub->save == 1)
		print_screen(cub);
	mlx_hook(cub->win_ptr, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->win_ptr, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->win_ptr, 17, 1L << 17, close_prog, cub);
	mlx_loop_hook(cub->mlx_ptr, &print_screen, cub);
	mlx_loop(cub->mlx_ptr);
}

int		check_is_ptcub(char *av, char *file)
{
	int i;
	int j;
	int k;
	
	i = ft_strlen(av);
	j = ft_strlen(file);
	k = i - j;
	while (i > k)
	{
		if (av[i] != file[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_cub3d cub;
	int fd;

	if (check_is_ptcub(av[1], ".cub") == 0)
		ft_error(" the first argument is not a .cub");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("bad file descriptor");
	init_cub3d(&cub);
	cub.save = 0;
	ft_printf("\n\n--->	START	<---\n\n");
	if (ac == 2)
	{
		start_parsing(fd, &cub);
		init_position(&cub.player, &cub);
		mlx_handle(&cub, av[1]);
	}
	if (ac == 3 && ft_strcmp("--save", av[2]) == 0)
	{
		cub.save = 1;
		start_parsing(open(av[1], O_RDONLY), &cub);
		init_position(&cub.player, &cub);
		mlx_handle(&cub, av[1]);
	}
	ft_error("bad arguments");
}

