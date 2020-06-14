/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:06:00 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:09:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move(t_cub3d *cub)
{
	cub->move.turnright ? turnright(cub) : 0;
	cub->move.turnleft ? turnleft(cub) : 0;
	cub->move.forward ? forward(cub) : 0;
	cub->move.backward ? backward(cub) : 0;
	cub->move.rightward ? rightward(cub) : 0;
	cub->move.leftward ? leftward(cub) : 0;
	cub->esc ? close_prog(cub) : 0;
}

void	forward(t_cub3d *cub)
{
	double movespeed;

	movespeed = 0.2;
	if (cub->closed_map[(int)(cub->player.posx + cub->player.dirx *
	movespeed)][(int)cub->player.posy] == '.')
		cub->player.posx += cub->player.dirx * movespeed;
	if (cub->closed_map[(int)cub->player.posx][(int)(cub->player.posy +
	cub->player.diry * movespeed)] == '.')
		cub->player.posy += cub->player.diry * movespeed;
}

void	backward(t_cub3d *cub)
{
	double movespeed;

	movespeed = 0.2;
	if (cub->closed_map[(int)(cub->player.posx - cub->player.dirx *
	movespeed)][(int)cub->player.posy] == '.')
		cub->player.posx -= cub->player.dirx * movespeed;
	if (cub->closed_map[(int)cub->player.posx][(int)(cub->player.posy -
	cub->player.diry * movespeed)] == '.')
		cub->player.posy -= cub->player.diry * movespeed;
}

void	rightward(t_cub3d *cub)
{
	double movespeed;

	movespeed = 0.2;
	if (cub->closed_map[(int)(cub->player.posx + cub->player.planex *
	movespeed)][(int)cub->player.posy] == '.')
		cub->player.posx += cub->player.planex * movespeed;
	if (cub->closed_map[(int)cub->player.posx][(int)(cub->player.posy +
	cub->player.planey * movespeed)] == '.')
		cub->player.posy += cub->player.planey * movespeed;
}

void	leftward(t_cub3d *cub)
{
	double movespeed;

	movespeed = 0.2;
	if (cub->closed_map[(int)(cub->player.posx - cub->player.planex *
	movespeed)][(int)cub->player.posy] == '.')
		cub->player.posx -= cub->player.planex * movespeed;
	if (cub->closed_map[(int)cub->player.posx][(int)(cub->player.posy -
	cub->player.planey * movespeed)] == '.')
		cub->player.posy -= cub->player.planey * movespeed;
}
