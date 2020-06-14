/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 00:00:52 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:11:21 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_dist_sprite(t_cub3d *cub, t_player *player)
{
	int i;

	i = 0;
	player->s_order = (int*)malloc(sizeof(int) * cub->map.sprite.nbr);
	player->s_dist = (double*)malloc(sizeof(double) * cub->map.sprite.nbr);
	while (i < cub->map.sprite.nbr)
	{
		player->s_order[i] = i;
		player->s_dist[i] = ((player->posx - cub->map.sprite.pos_sprite[i][0])
		* (player->posx - cub->map.sprite.pos_sprite[i][0]) + (player->posy -
		cub->map.sprite.pos_sprite[i][1]) *
		(player->posy - cub->map.sprite.pos_sprite[i][1]));
		i++;
	}
}

void	sort_sprite(t_cub3d *cub, t_player *player)
{
	int i;
	int stock;
	int stock_d;

	i = 0;
	while (i < cub->map.sprite.nbr)
	{
		if (i + 1 < cub->map.sprite.nbr && player->s_dist[i] <
		player->s_dist[i + 1])
		{
			stock = player->s_order[i + 1];
			stock_d = player->s_dist[i + 1];
			player->s_order[i + 1] = player->s_order[i];
			player->s_dist[i + 1] = player->s_dist[i];
			player->s_order[i] = stock;
			player->s_dist[i] = stock_d;
			i = -1;
		}
		i++;
	}
}

void	init_sprite_2(t_cub3d *cub)
{
	cub->map.sprite.height = abs((int)(cub->height / (cub->map.sprite.transy)));
	cub->map.sprite. drawstarty = -cub->map.sprite.height / 2 + cub->height / 2;
	if (cub->map.sprite. drawstarty < 0)
		cub->map.sprite. drawstarty = 0;
	cub->map.sprite.drawendy = cub->map.sprite.height / 2 + cub->height / 2;
	if (cub->map.sprite.drawendy >= cub->height)
		cub->map.sprite.drawendy = cub->height - 1;
	cub->map.sprite.width = abs((int)(cub->height / (cub->map.sprite.transy)));
	cub->map.sprite. drawstartx = -cub->map.sprite.width / 2 +
	cub->map.sprite.screenx;
	if (cub->map.sprite. drawstartx < 0)
		cub->map.sprite. drawstartx = 0;
	cub->map.sprite.drawendx = cub->map.sprite.width / 2 +
	cub->map.sprite.screenx;
	if (cub->map.sprite.drawendx >= cub->width)
		cub->map.sprite.drawendx = cub->width - 1;
}

void	init_sprite(t_cub3d *cub, t_player *player)
{
	cub->map.sprite.indet = 1.0 / (player->planex * player->diry -
	player->dirx * player->planey);
	cub->map.sprite.transx = cub->map.sprite.indet * (player->diry *
				cub->map.sprite.x - player->dirx * cub->map.sprite.y);
	cub->map.sprite.transy = cub->map.sprite.indet * (-player->planey *
				cub->map.sprite.x + player->planex * cub->map.sprite.y);
	cub->map.sprite.screenx = (int)((cub->width / 2) *
		(1 + cub->map.sprite.transx / cub->map.sprite.transy));
	init_sprite_2(cub);
}

void	gestion_sprite(t_cub3d *cub, t_player *player, double *zbuffer)
{
	int i;

	i = 0;
	check_dist_sprite(cub, player);
	sort_sprite(cub, player);
	while (i < cub->map.sprite.nbr)
	{
		cub->map.sprite.x = cub->map.sprite.pos_sprite[player->s_order[i]][0] -
		player->posx + 0.5;
		cub->map.sprite.y = cub->map.sprite.pos_sprite[player->s_order[i]][1] -
		player->posy + 0.5;
		init_sprite(cub, player);
		while (cub->map.sprite. drawstartx < cub->map.sprite.drawendx)
		{
			draw_sprite(cub, player, zbuffer);
			cub->map.sprite. drawstartx++;
		}
		i++;
	}
	free(player->s_order);
	free(player->s_dist);
}
