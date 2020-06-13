/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:17:26 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 22:28:18 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_direction2(t_cub3d *cub)
{
	if (cub->orientation == 'N')
	{
		cub->player.dirX = -1.0;
		cub->player.dirY = 0.0;
		cub->player.planeX = cub->player.dirY * tan(1.25 / 2);
		cub->player.planeY = -cub->player.dirX * tan(1.25 / 2);
	}
	if (cub->orientation == 'S')
	{
		cub->player.dirX = 1.0;
		cub->player.dirY = 0.0;
		cub->player.planeX = -cub->player.dirY * tan(1.25 / 2);
		cub->player.planeY = -cub->player.dirX * tan(1.25 / 2);
	}
}

void	init_direction(t_cub3d *cub)
{
	init_direction2(cub);
	if (cub->orientation == 'W')
	{
		cub->player.dirX = 0.0;
		cub->player.dirY = -1.0;
		cub->player.planeX = cub->player.dirY * tan(1.25 / 2);
		cub->player.planeY = cub->player.dirX * tan(1.25 / 2);
	}
	if (cub->orientation == 'E')
	{
		cub->player.dirX = 1.0;
		cub->player.dirY = 1.0;
		cub->player.planeX = cub->player.dirY * tan(1.25 / 2);
		cub->player.planeY = -cub->player.dirX * tan(1.25 / 2);
	}
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
