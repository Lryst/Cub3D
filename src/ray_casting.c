/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:23:52 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:09:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_wall_hit_2(t_cub3d *cub, t_player *player)
{
	if (player->side == 1)
	{
		if (player->raydiry < 0)
			player->side += 2;
	}
	else
	{
		if (player->raydirx < 0)
			player->side += 2;
	}
	if (player->side == 0 || player->side == 2)
		player->perpwalldist = (player->mapx - player->posx +
		(1 - player->stepx) / 2) / player->raydirx;
	else
		player->perpwalldist = (player->mapy - player->posy +
		(1 - player->stepy) / 2) / player->raydiry;
	draw_plan(cub, player);
}

void	check_wall_hit(t_cub3d *cub, t_player *player)
{
	while (player->hit == 0)
	{
		if (player->sidedistx < player->sidedisty)
		{
			player->sidedistx += player->deltadistx;
			player->mapx += player->stepx;
			player->side = 0;
		}
		else
		{
			player->sidedisty += player->deltadisty;
			player->mapy += player->stepy;
			player->side = 1;
		}
		cub->closed_map[player->mapx][player->mapy] == '1' ?
		player->hit = 1 : 0;
	}
	check_wall_hit_2(cub, player);
}

void	get_side_dist(t_cub3d *cub, t_player *player)
{
	if (player->raydirx < 0)
	{
		player->stepx = -1;
		player->sidedistx = (player->posx - player->mapx) * player->deltadistx;
	}
	else
	{
		player->stepx = 1;
		player->sidedistx = (player->mapx + 1.0 - player->posx) *
		player->deltadistx;
	}
	if (player->raydiry < 0)
	{
		player->stepy = -1;
		player->sidedisty = (player->posy - player->mapy) * player->deltadisty;
	}
	else
	{
		player->stepy = 1;
		player->sidedisty = (player->mapy + 1.0 - player->posy) *
		player->deltadisty;
	}
	check_wall_hit(cub, player);
}

void	init_raycasting(t_cub3d *cub, t_player *player)
{
	player->y = -1;
	player->camerax = 2 * player->x / (double)cub->width - 1;
	player->raydirx = player->dirx + player->planex * player->camerax;
	player->raydiry = player->diry + player->planey * player->camerax;
	player->mapx = (int)player->posx;
	player->mapy = (int)player->posy;
	player->deltadistx = sqrt(1 + (player->raydiry * player->raydiry)
		/ (player->raydirx * player->raydirx));
	player->deltadisty = sqrt(1 + (player->raydirx * player->raydirx)
		/ (player->raydiry * player->raydiry));
	player->hit = 0;
	get_side_dist(cub, player);
}

void	start_ray_casting(t_cub3d *cub, t_player *player)
{
	double zbuffer[cub->width];

	player->x = -1;
	player->y = -1;
	while (++player->x < cub->width)
	{
		init_raycasting(cub, player);
		zbuffer[player->x] = player->perpwalldist;
	}
	gestion_sprite(cub, player, zbuffer);
	if (cub->save == 1)
	{
		save(cub);
	}
}
