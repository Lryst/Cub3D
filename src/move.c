/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:06:00 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 21:41:19 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void  turnRight(t_cub3d *ptr)
{
    double rotSpeed = 0.1;
	ptr->p.oldDirx = ptr->p.dirx;
	ptr->p.dirx = ptr->p.dirx * cos(-rotSpeed) - ptr->p.diry * sin(-rotSpeed);
	ptr->p.diry = ptr->p.oldDirx * sin(-rotSpeed) + ptr->p.diry * cos(-rotSpeed);
	double oldPlanex = ptr->p.planex;
	ptr->p.planex = ptr->p.planex * cos(-rotSpeed) - ptr->p.planey * sin(-rotSpeed);
	ptr->p.planey = oldPlanex * sin(-rotSpeed) + ptr->p.planey * cos(-rotSpeed);
}

void turnLeft(t_cub3d *ptr)
{
    double rotSpeed = 0.1;    
      //both camera direction and camera plane must be rotated
      ptr->p.oldDirx = ptr->p.dirx;
      ptr->p.dirx = ptr->p.dirx * cos(rotSpeed) - ptr->p.diry * sin(rotSpeed);
      ptr->p.diry = ptr->p.oldDirx * sin(rotSpeed) + ptr->p.diry * cos(rotSpeed);
      ptr->p.oldplanex = ptr->p.planex;
      ptr->p.planex = ptr->p.planex * cos(rotSpeed) - ptr->p.planey * sin(rotSpeed);
      ptr->p.planey = ptr->p.oldplanex * sin(rotSpeed) + ptr->p.planey * cos(rotSpeed);
}

void forward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->p.posx + ptr->p.dirx * moveSpeed)][(int)ptr->p.posy] == '.')
        ptr->p.posx += ptr->p.dirx * moveSpeed;
    if(ptr->closed_map[(int)ptr->p.posx][(int)(ptr->p.posy + ptr->p.diry * moveSpeed)] == '.')
        ptr->p.posy += ptr->p.diry * moveSpeed;
}

void backward(t_cub3d *ptr)
{
    double moveSpeed = 0.2;
    if(ptr->closed_map[(int)(ptr->p.posx - ptr->p.dirx * moveSpeed)][(int)ptr->p.posy] == '.')
        ptr->p.posx -= ptr->p.dirx * moveSpeed;
    if(ptr->closed_map[(int)ptr->p.posx][(int)(ptr->p.posy - ptr->p.diry * moveSpeed)] == '.')
        ptr->p.posy -= ptr->p.diry * moveSpeed;
}