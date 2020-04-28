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

void  turnRight(t_cub3d *ptr)
{
    double rotSpeed = 0.1;
	ptr->player.oldDirx = ptr->player.dirX;
	ptr->player.dirX = ptr->player.dirX * cos(-rotSpeed) - ptr->player.dirY * sin(-rotSpeed);
	ptr->player.dirY = ptr->player.oldDirx * sin(-rotSpeed) + ptr->player.dirY * cos(-rotSpeed);
	double oldPlanex = ptr->player.planeX;
	ptr->player.planeX = ptr->player.planeX * cos(-rotSpeed) - ptr->player.planeY * sin(-rotSpeed);
	ptr->player.planeY = oldPlanex * sin(-rotSpeed) + ptr->player.planeY * cos(-rotSpeed);
}

void turnLeft(t_cub3d *ptr)
{
    double rotSpeed = 0.1;    
      //both camera direction and camera plane must be rotated
      ptr->player.oldDirx = ptr->player.dirX;
      ptr->player.dirX = ptr->player.dirX * cos(rotSpeed) - ptr->player.dirY * sin(rotSpeed);
      ptr->player.dirY = ptr->player.oldDirx * sin(rotSpeed) + ptr->player.dirY * cos(rotSpeed);
      ptr->player.oldplaneX = ptr->player.planeX;
      ptr->player.planeX = ptr->player.planeX * cos(rotSpeed) - ptr->player.planeY * sin(rotSpeed);
      ptr->player.planeY = ptr->player.oldplaneX * sin(rotSpeed) + ptr->player.planeY * cos(rotSpeed);
}

void forward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->player.posX + ptr->player.dirX * moveSpeed)][(int)ptr->player.posY] == '.')
        ptr->player.posX += ptr->player.dirX * moveSpeed;
    if(ptr->closed_map[(int)ptr->player.posX][(int)(ptr->player.posY + ptr->player.dirY * moveSpeed)] == '.')
        ptr->player.posY += ptr->player.dirY * moveSpeed;
}

void backward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->player.posX - ptr->player.dirX * moveSpeed)][(int)ptr->player.posY] == '.')
        ptr->player.posX -= ptr->player.dirX * moveSpeed;
    if(ptr->closed_map[(int)ptr->player.posX][(int)(ptr->player.posY - ptr->player.dirY * moveSpeed)] == '.')
        ptr->player.posY -= ptr->player.dirY * moveSpeed;
}

void rightward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->player.posX + ptr->player.planeX * moveSpeed)][(int)ptr->player.posY] == '.')
        ptr->player.posX += ptr->player.planeX * moveSpeed;
    if(ptr->closed_map[(int)ptr->player.posX][(int)(ptr->player.posY + ptr->player.planeY * moveSpeed)] == '.')
        ptr->player.posY += ptr->player.planeY * moveSpeed;
}

void    leftward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->player.posX - ptr->player.planeX * moveSpeed)][(int)ptr->player.posY] == '.')
        ptr->player.posX -= ptr->player.planeX * moveSpeed;
    if(ptr->closed_map[(int)ptr->player.posX][(int)(ptr->player.posY - ptr->player.planeY * moveSpeed)] == '.')
        ptr->player.posY -= ptr->player.planeY * moveSpeed;
}

/*
reculer
if (keyDown (SDLK_DOWN))
    {
      if (worldMap [int (posX - dirX * moveSpeed)] [int (posY)] == false) posX - = dirX * moveSpeed;
      if (worldMap [int (posX)] [int (posY - dirY * moveSpeed)] == false) posY - = dirY * moveSpeed;
    }*/