/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:14:08 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:45:53 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_pressed(int key, t_cub3d *cub)
{
	key == 65307 ? cub->esc = 1 : 0;
	key == 119 ? cub->move.forward = 1 : 0;
	key == 115 ? cub->move.backward = 1 : 0;
	key == 65363 ? cub->move.turnright = 1 : 0;
	key == 65361 ? cub->move.turnleft = 1 : 0;
	key == 100 ? cub->move.rightward = 1 : 0;
	key == 97 ? cub->move.leftward = 1 : 0;
	return (0);
}

int		key_release(int key, t_cub3d *cub)
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
	cub->img_ptr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
	&cub->size_line, &cub->endian);
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
