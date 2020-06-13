/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:06:00 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 22:54:33 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	move(t_cub3d *cub)
{
	cub->move.turnright ? turnRight(cub) : 0;
	cub->move.turnleft ? turnLeft(cub) : 0;
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
	if (cub->closed_map[(int)(cub->player.posX + cub->player.dirX *
	movespeed)][(int)cub->player.posY] == '.')
		cub->player.posX += cub->player.dirX * movespeed;
	if (cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY +
	cub->player.dirY * movespeed)] == '.')
		cub->player.posY += cub->player.dirY * movespeed;
}

void	backward(t_cub3d *cub)
{
	double movespeed;

	movespeed = 0.2;
	if (cub->closed_map[(int)(cub->player.posX - cub->player.dirX *
	movespeed)][(int)cub->player.posY] == '.')
		cub->player.posX -= cub->player.dirX * movespeed;
	if (cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY -
	cub->player.dirY * movespeed)] == '.')
		cub->player.posY -= cub->player.dirY * movespeed;
}

void	rightward(t_cub3d *cub)
{
	double movespeed;

	movespeed = 0.2;
	if (cub->closed_map[(int)(cub->player.posX + cub->player.planeX *
	movespeed)][(int)cub->player.posY] == '.')
		cub->player.posX += cub->player.planeX * movespeed;
	if (cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY +
	cub->player.planeY * movespeed)] == '.')
		cub->player.posY += cub->player.planeY * movespeed;
}

void	leftward(t_cub3d *cub)
{
	double movespeed;

	movespeed = 0.2;
	if (cub->closed_map[(int)(cub->player.posX - cub->player.planeX *
	movespeed)][(int)cub->player.posY] == '.')
		cub->player.posX -= cub->player.planeX * movespeed;
	if (cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY -
	cub->player.planeY * movespeed)] == '.')
		cub->player.posY -= cub->player.planeY * movespeed;
}
