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
		//ptr->player.oldDirx = ptr->player.dirX;
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

void	init_player(t_player *player, t_cub3d *cub)
{
	
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
    //printf("%d\n", key);
	//printf("coucou 6\n");
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
	//printf("coucou 6bis\n");
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
	//printf ("//print 1\n");
	if (cub->img != NULL)
	{
		//printf("cub->img != NULL\n");
	}
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
	//printf("coucou 13 wesh\n");
	if (!(mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0)))
		//printf("mlx_put_image_to_window PAS POSSIBLE !\n");
	if (cub->img != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->img);
	return (1);
}

void	mlx_handle(t_cub3d *cub, char *av)
{
	//printf("coucou 1\n");
    cub->mlx_ptr = mlx_init();
	//printf("coucou 2\n");
	if (cub->mlx_ptr == NULL)
	{
		//printf("mlx_ptr == NULL, alos quil a etait initié");
		return;
	}
    cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->width, cub->height, av);
	//printf("coucou 3\n");
	set_img(cub);
	//mlx_key_hook(cub->win_ptr, key_pressed, ptr);
	//printf("coucou 5/6\n");
	/*mlx_hook(cub->win_ptr, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->win_ptr, 2, 1L <<  0, key_pressed, cub);*/
	mlx_hook(cub->win_ptr, 2, 0, key_pressed, cub);
	mlx_hook(cub->win_ptr, 3, 0, key_release, cub);
	//printf("coucou 6 ter\n");
	if (cub->mlx_ptr == NULL || cub->win_ptr == NULL)
	{
		//printf("mlx_ptr == NULL, alos quil a etait initié");
		return;
	}
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
	init_position(&cub);
	mlx_handle(&cub, av[1]);
	//printf("%d\n", atoi("223,45,0"));
	//system("leaks a.out");
}