/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:42:04 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 23:44:05 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	turnright2(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	cub->player.oldDirx = cub->player.dirX;
	cub->player.dirX = cub->player.dirX * cos(rotspeed) -
	cub->player.dirY * sin(rotspeed);
	cub->player.dirY = cub->player.oldDirx * sin(rotspeed) +
	cub->player.dirY * cos(rotspeed);
	cub->player.oldplaneX = cub->player.planeX;
	cub->player.planeX = cub->player.planeX * cos(rotspeed) -
	cub->player.planeY * sin(rotspeed);
	cub->player.planeY = cub->player.oldplaneX * sin(rotspeed) +
	cub->player.planeY * cos(rotspeed);
}

void	turnright(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	if (cub->orientation == 'N' || cub->orientation == 'W' ||
	cub->orientation == 'S')
	{
		cub->player.oldDirx = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(-rotspeed) -
		cub->player.dirY * sin(-rotspeed);
		cub->player.dirY = cub->player.oldDirx * sin(-rotspeed) +
		cub->player.dirY * cos(-rotspeed);
		cub->player.oldplaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(-rotspeed) -
		cub->player.planeY * sin(-rotspeed);
		cub->player.planeY = cub->player.oldplaneX * sin(-rotspeed) +
		cub->player.planeY * cos(-rotspeed);
	}
	else
		turnright2(cub);
}

void	turnleft2(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	cub->player.oldDirx = cub->player.dirX;
	cub->player.dirX = cub->player.dirX * cos(-rotspeed) -
	cub->player.dirY * sin(-rotspeed);
	cub->player.dirY = cub->player.oldDirx * sin(-rotspeed) +
	cub->player.dirY * cos(-rotspeed);
	cub->player.oldplaneX = cub->player.planeX;
	cub->player.planeX = cub->player.planeX * cos(-rotspeed) -
	cub->player.planeY * sin(-rotspeed);
	cub->player.planeY = cub->player.oldplaneX * sin(-rotspeed) +
	cub->player.planeY * cos(-rotspeed);
}

void	turnleft(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	if (cub->orientation == 'N' || cub->orientation == 'W' ||
	cub->orientation == 'S')
	{
		cub->player.oldDirx = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(rotspeed) -
		cub->player.dirY * sin(rotspeed);
		cub->player.dirY = cub->player.oldDirx * sin(rotspeed) +
		cub->player.dirY * cos(rotspeed);
		cub->player.oldplaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(rotspeed) -
		cub->player.planeY * sin(rotspeed);
		cub->player.planeY = cub->player.oldplaneX * sin(rotspeed) +
		cub->player.planeY * cos(rotspeed);
	}
	else
		turnleft2(cub);
}
