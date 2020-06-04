/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:06:00 by lryst             #+#    #+#             */
/*   Updated: 2020/03/10 15:24:19 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    move(t_cub3d *cub)
{
    if (cub->save == 0)
    {
        cub->move.turnright ? turnRight(cub) : 0;
        cub->move.turnleft ? turnLeft(cub) : 0;
        cub->move.forward ? forward(cub) : 0;
        cub->move.backward ? backward(cub) : 0;
        cub->move.rightward ? rightward(cub) : 0;
        cub->move.leftward ? leftward(cub) : 0;
        cub->esc ? close_prog(cub) : 0;
    }
    return;
}

void  turnRight(t_cub3d *cub)
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

void turnLeft(t_cub3d *cub)
{
    double rotSpeed;

    rotSpeed = 0.1;    
      //both camera direction and camera plane must be rotated
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

void forward(t_cub3d *cub)
{
    double moveSpeed = 0.2;
    if(cub->closed_map[(int)(cub->player.posX + cub->player.dirX * moveSpeed)][(int)cub->player.posY] == '.')
        cub->player.posX += cub->player.dirX * moveSpeed;
    if(cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY + cub->player.dirY * moveSpeed)] == '.')
        cub->player.posY += cub->player.dirY * moveSpeed;
}

void backward(t_cub3d *cub)
{
    double moveSpeed = 0.2;
    if(cub->closed_map[(int)(cub->player.posX - cub->player.dirX * moveSpeed)][(int)cub->player.posY] == '.')
        cub->player.posX -= cub->player.dirX * moveSpeed;
    if(cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY - cub->player.dirY * moveSpeed)] == '.')
        cub->player.posY -= cub->player.dirY * moveSpeed;
}

void rightward(t_cub3d *cub)
{
    double moveSpeed = 0.2;
    if(cub->closed_map[(int)(cub->player.posX + cub->player.planeX * moveSpeed)][(int)cub->player.posY] == '.')
        cub->player.posX += cub->player.planeX * moveSpeed;
    if(cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY + cub->player.planeY * moveSpeed)] == '.')
        cub->player.posY += cub->player.planeY * moveSpeed;
}

void    leftward(t_cub3d *cub)
{
    double moveSpeed = 0.2;
    if(cub->closed_map[(int)(cub->player.posX - cub->player.planeX * moveSpeed)][(int)cub->player.posY] == '.')
        cub->player.posX -= cub->player.planeX * moveSpeed;
    if(cub->closed_map[(int)cub->player.posX][(int)(cub->player.posY - cub->player.planeY * moveSpeed)] == '.')
        cub->player.posY -= cub->player.planeY * moveSpeed;
}

/*
reculer
if (keyDown (SDLK_DOWN))
    {
      if (worldMap [int (posX - dirX * moveSpeed)] [int (posY)] == false) posX - = dirX * moveSpeed;
      if (worldMap [int (posX)] [int (posY - dirY * moveSpeed)] == false) posY - = dirY * moveSpeed;
    }*/