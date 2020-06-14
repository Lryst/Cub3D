/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:42:04 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:09:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	turnright2(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	cub->player.olddirx = cub->player.dirx;
	cub->player.dirx = cub->player.dirx * cos(rotspeed) -
	cub->player.diry * sin(rotspeed);
	cub->player.diry = cub->player.olddirx * sin(rotspeed) +
	cub->player.diry * cos(rotspeed);
	cub->player.oldplanex = cub->player.planex;
	cub->player.planex = cub->player.planex * cos(rotspeed) -
	cub->player.planey * sin(rotspeed);
	cub->player.planey = cub->player.oldplanex * sin(rotspeed) +
	cub->player.planey * cos(rotspeed);
}

void	turnright(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	if (cub->orientation == 'N' || cub->orientation == 'W' ||
	cub->orientation == 'S')
	{
		cub->player.olddirx = cub->player.dirx;
		cub->player.dirx = cub->player.dirx * cos(-rotspeed) -
		cub->player.diry * sin(-rotspeed);
		cub->player.diry = cub->player.olddirx * sin(-rotspeed) +
		cub->player.diry * cos(-rotspeed);
		cub->player.oldplanex = cub->player.planex;
		cub->player.planex = cub->player.planex * cos(-rotspeed) -
		cub->player.planey * sin(-rotspeed);
		cub->player.planey = cub->player.oldplanex * sin(-rotspeed) +
		cub->player.planey * cos(-rotspeed);
	}
	else
		turnright2(cub);
}

void	turnleft2(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	cub->player.olddirx = cub->player.dirx;
	cub->player.dirx = cub->player.dirx * cos(-rotspeed) -
	cub->player.diry * sin(-rotspeed);
	cub->player.diry = cub->player.olddirx * sin(-rotspeed) +
	cub->player.diry * cos(-rotspeed);
	cub->player.oldplanex = cub->player.planex;
	cub->player.planex = cub->player.planex * cos(-rotspeed) -
	cub->player.planey * sin(-rotspeed);
	cub->player.planey = cub->player.oldplanex * sin(-rotspeed) +
	cub->player.planey * cos(-rotspeed);
}

void	turnleft(t_cub3d *cub)
{
	double rotspeed;

	rotspeed = 0.1;
	if (cub->orientation == 'N' || cub->orientation == 'W' ||
	cub->orientation == 'S')
	{
		cub->player.olddirx = cub->player.dirx;
		cub->player.dirx = cub->player.dirx * cos(rotspeed) -
		cub->player.diry * sin(rotspeed);
		cub->player.diry = cub->player.olddirx * sin(rotspeed) +
		cub->player.diry * cos(rotspeed);
		cub->player.oldplanex = cub->player.planex;
		cub->player.planex = cub->player.planex * cos(rotspeed) -
		cub->player.planey * sin(rotspeed);
		cub->player.planey = cub->player.oldplanex * sin(rotspeed) +
		cub->player.planey * cos(rotspeed);
	}
	else
		turnleft2(cub);
}
