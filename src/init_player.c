/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:17:26 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:09:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_direction2(t_cub3d *cub)
{
	if (cub->orientation == 'N')
	{
		cub->player.dirx = -1.0;
		cub->player.diry = 0.0;
		cub->player.planex = cub->player.diry * tan(1.25 / 2);
		cub->player.planey = -cub->player.dirx * tan(1.25 / 2);
	}
	if (cub->orientation == 'S')
	{
		cub->player.dirx = 1.0;
		cub->player.diry = 0.0;
		cub->player.planex = -cub->player.diry * tan(1.25 / 2);
		cub->player.planey = -cub->player.dirx * tan(1.25 / 2);
	}
}

void	init_direction(t_cub3d *cub)
{
	init_direction2(cub);
	if (cub->orientation == 'W')
	{
		cub->player.dirx = 0.0;
		cub->player.diry = -1.0;
		cub->player.planex = cub->player.diry * tan(1.25 / 2);
		cub->player.planey = cub->player.dirx * tan(1.25 / 2);
	}
	if (cub->orientation == 'E')
	{
		cub->player.dirx = 1.0;
		cub->player.diry = 1.0;
		cub->player.planex = cub->player.diry * tan(1.25 / 2);
		cub->player.planey = -cub->player.dirx * tan(1.25 / 2);
	}
}

void	init_position(t_player *player, t_cub3d *cub)
{
	player->posx = (double)cub->posx + 0.5;
	player->posy = (double)cub->posy + 0.5;
	player->planex = 0.0;
	player->planey = 0.66;
	player->time = 0.0;
	player->oldtime = 0.0;
	init_direction(cub);
}
