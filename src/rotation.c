/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:42:04 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 22:45:37 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void    turnRight(t_cub3d *cub)
{
	double rotSpeed;

	rotSpeed = 0.1;
	if (cub->orientation == 'N' || cub->orientation == 'W' || cub->orientation == 'S')
	{
		cub->player.oldDirx = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(-rotSpeed) - cub->player.dirY * sin(-rotSpeed);
		cub->player.dirY = cub->player.oldDirx * sin(-rotSpeed) + cub->player.dirY * cos(-rotSpeed);
		cub->player.oldplaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(-rotSpeed) - cub->player.planeY * sin(-rotSpeed);
		cub->player.planeY = cub->player.oldplaneX * sin(-rotSpeed) + cub->player.planeY * cos(-rotSpeed);
	}
	else
	{
		cub->player.oldDirx = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(rotSpeed) - cub->player.dirY * sin(rotSpeed);
		cub->player.dirY = cub->player.oldDirx * sin(rotSpeed) + cub->player.dirY * cos(rotSpeed);
		cub->player.oldplaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(rotSpeed) - cub->player.planeY * sin(rotSpeed);
		cub->player.planeY = cub->player.oldplaneX * sin(rotSpeed) + cub->player.planeY * cos(rotSpeed);
	}
	
}

void	turnLeft(t_cub3d *cub)
{
	double rotSpeed;

	rotSpeed = 0.1;    
	if (cub->orientation == 'N' || cub->orientation == 'W' || cub->orientation == 'S')
	{
		cub->player.oldDirx = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(rotSpeed) - cub->player.dirY * sin(rotSpeed);
		cub->player.dirY = cub->player.oldDirx * sin(rotSpeed) + cub->player.dirY * cos(rotSpeed);
		cub->player.oldplaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(rotSpeed) - cub->player.planeY * sin(rotSpeed);
		cub->player.planeY = cub->player.oldplaneX * sin(rotSpeed) + cub->player.planeY * cos(rotSpeed);
	}
	else
	{
		cub->player.oldDirx = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(-rotSpeed) - cub->player.dirY * sin(-rotSpeed);
		cub->player.dirY = cub->player.oldDirx * sin(-rotSpeed) + cub->player.dirY * cos(-rotSpeed);
		cub->player.oldplaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(-rotSpeed) - cub->player.planeY * sin(-rotSpeed);
		cub->player.planeY = cub->player.oldplaneX * sin(-rotSpeed) + cub->player.planeY * cos(-rotSpeed);
	}
}