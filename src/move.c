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
	ptr->p.oldDirx = ptr->p.dirX;
	ptr->p.dirX = ptr->p.dirX * cos(-rotSpeed) - ptr->p.dirY * sin(-rotSpeed);
	ptr->p.dirY = ptr->p.oldDirx * sin(-rotSpeed) + ptr->p.dirY * cos(-rotSpeed);
	double oldPlanex = ptr->p.planeX;
	ptr->p.planeX = ptr->p.planeX * cos(-rotSpeed) - ptr->p.planeY * sin(-rotSpeed);
	ptr->p.planeY = oldPlanex * sin(-rotSpeed) + ptr->p.planeY * cos(-rotSpeed);
}

void turnLeft(t_cub3d *ptr)
{
    double rotSpeed = 0.1;    
      //both camera direction and camera plane must be rotated
      ptr->p.oldDirx = ptr->p.dirX;
      ptr->p.dirX = ptr->p.dirX * cos(rotSpeed) - ptr->p.dirY * sin(rotSpeed);
      ptr->p.dirY = ptr->p.oldDirx * sin(rotSpeed) + ptr->p.dirY * cos(rotSpeed);
      ptr->p.oldplaneX = ptr->p.planeX;
      ptr->p.planeX = ptr->p.planeX * cos(rotSpeed) - ptr->p.planeY * sin(rotSpeed);
      ptr->p.planeY = ptr->p.oldplaneX * sin(rotSpeed) + ptr->p.planeY * cos(rotSpeed);
}

void forward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->p.posX + ptr->p.dirX * moveSpeed)][(int)ptr->p.posY] == '.')
        ptr->p.posX += ptr->p.dirX * moveSpeed;
    if(ptr->closed_map[(int)ptr->p.posX][(int)(ptr->p.posY + ptr->p.dirY * moveSpeed)] == '.')
        ptr->p.posY += ptr->p.dirY * moveSpeed;
}

void backward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->p.posX - ptr->p.dirX * moveSpeed)][(int)ptr->p.posY] == '.')
        ptr->p.posX -= ptr->p.dirX * moveSpeed;
    if(ptr->closed_map[(int)ptr->p.posX][(int)(ptr->p.posY - ptr->p.dirY * moveSpeed)] == '.')
        ptr->p.posY -= ptr->p.dirY * moveSpeed;
}

void rightward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->p.posX + ptr->p.planeX * moveSpeed)][(int)ptr->p.posY] == '.')
        ptr->p.posX += ptr->p.planeX * moveSpeed;
    if(ptr->closed_map[(int)ptr->p.posX][(int)(ptr->p.posY + ptr->p.planeY * moveSpeed)] == '.')
        ptr->p.posY += ptr->p.planeY * moveSpeed;
}

void    leftward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->p.posX - ptr->p.planeX * moveSpeed)][(int)ptr->p.posY] == '.')
        ptr->p.posX -= ptr->p.planeX * moveSpeed;
    if(ptr->closed_map[(int)ptr->p.posX][(int)(ptr->p.posY - ptr->p.planeY * moveSpeed)] == '.')
        ptr->p.posY -= ptr->p.planeY * moveSpeed;
}

/*
reculer
if (keyDown (SDLK_DOWN))
    {
      if (worldMap [int (posX - dirX * moveSpeed)] [int (posY)] == false) posX - = dirX * moveSpeed;
      if (worldMap [int (posX)] [int (posY - dirY * moveSpeed)] == false) posY - = dirY * moveSpeed;
    }*/