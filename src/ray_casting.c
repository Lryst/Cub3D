/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:15:05 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 21:56:19 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ray_caster(t_cub3d *q, t_player *p)
{
	int i;
	
	i = -1;
	while (++i < q->width)
	{
		p->camerax = 2 * i / (double)q->width - 1;
		p->rayDirx = p->dirx + p->planex * p->camerax;
		p->rayDiry = p->diry + p->planey * p->camerax;
		p->mapx = (int)p->posx;
		p->mapy = (int)p->posy;
		p->deltaDistx = ABS(1 / p->rayDirx);
		p->deltaDisty = ABS(1 / p->rayDiry);
		//p->perpWallDist;
		p->hit = 0;
		if (p->rayDirx < 0)
		{
			p->stepx = -1;
			p->sideDistx = (p->posx - p->mapx) * p->deltaDistx;
		}
		else
		{
			p->stepx = 1;
			p->sideDistx = (p->mapx + 1.0 - p->posx) * p->deltaDistx;
		}
		if(p->rayDiry < 0)
		{
			p->stepy = -1;
			p->sideDisty = (p->posy - p->mapy) * p->deltaDisty;
		}
		else
		{
			p->stepy = 1;
			p->sideDisty = (p->mapy + 1.0 - p->posy) * p->deltaDisty;
		}
		while (p->hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(p->sideDistx < p->sideDisty)
			{
				p->sideDistx += p->deltaDistx;
				p->mapx += p->stepx;
				p->side = 0;
			}
			else
			{
				p->sideDisty += p->deltaDisty;
				p->mapy += p->stepy;
				p->side = 1;
			}
			//Check if ray has hit a wall
			q->closed_map[p->mapx][p->mapy] != '.' ? p->hit = 1 : 0;
		}
		//Calculate distance projected on camera dir
		if(p->side == 0)
			p->perpWallDist = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->rayDirx;
      	else
			p->perpWallDist = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->rayDiry;
		
		//Calculate height of line to draw on screen
      	p->lineHeight = (int)(q->height / p->perpWallDist);

      	//calculate lowest and highest pixel to fill in current stripe
      	p->drawStart = -p->lineHeight / 2 + q->height / 2;
      	if(p->drawStart < 0)
	  		p->drawStart = 0;
      	p->drawEnd = p->lineHeight / 2 + q->height / 2;
      	if(p->drawEnd >= q->height)
			p->drawEnd = q->height - 1;
		p->color = 0xEF96C4;
		if(p->side == 1)
			p->color = 0xF90985;
		int j = -1;
		while (++j < q->height)
			*(int*)(q->img_ptr + j * 4 * q->width + i * 4)  = j >= p->drawStart && j <= p->drawEnd ? p->color : 0;
			
	}
}