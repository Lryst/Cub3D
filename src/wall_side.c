/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 00:09:22 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:09:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	side_2(t_cub3d *cub, t_player *player)
{
	player->texx = (int)(player->wallx * (double)cub->no.width);
	player->texx = cub->no.width - player->texx - 1;
	player->step = 1.0 * cub->no.height / player->lineheight;
	player->texpos = (player->drawstart - cub->height /
	2 + player->lineheight / 2) * player->step;
	while (++player->y < cub->height)
	{
		if (player->y >= player->drawstart && player->y <= player->drawend)
		{
			player->texy = (int)player->texpos & (cub->no.height - 1);
			player->texpos += player->step;
			player->color = cub->tab_textures[0][cub->no.height * player->texy
			+ player->texx];
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x *
			4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x *
			4) = player->y < player->drawstart ? mlx_get_color_value(
			cub->mlx_ptr, cub->f.color) :
			mlx_get_color_value(cub->mlx_ptr, cub->c.color);
		}
	}
}

void	side_1(t_cub3d *cub, t_player *player)
{
	player->texx = (int)(player->wallx * (double)cub->ea.width);
	player->texx = cub->ea.width - player->texx - 1;
	player->step = 1.0 * cub->ea.height / player->lineheight;
	player->texpos = (player->drawstart - cub->height /
		2 + player->lineheight / 2) * player->step;
	while (++player->y < cub->height)
	{
		if (player->y >= player->drawstart && player->y <= player->drawend)
		{
			player->texy = (int)player->texpos & (cub->ea.height - 1);
			player->texpos += player->step;
			player->color = cub->tab_textures[1][cub->ea.height * player->texy
			+ player->texx];
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x *
			4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x *
			4) = player->y < player->drawstart ? mlx_get_color_value(
			cub->mlx_ptr, cub->f.color) :
			mlx_get_color_value(cub->mlx_ptr, cub->c.color);
		}
	}
}

void	side_0(t_cub3d *cub, t_player *player)
{
	player->texx = (int)(player->wallx * (double)cub->so.width);
	player->texx = cub->so.width - player->texx - 1;
	player->step = 1.0 * cub->so.height / player->lineheight;
	player->texpos = (player->drawstart - cub->height /
	2 + player->lineheight / 2) * player->step;
	while (++player->y < cub->height)
	{
		if (player->y >= player->drawstart && player->y <= player->drawend)
		{
			player->texy = (int)player->texpos & (cub->so.height - 1);
			player->texpos += player->step;
			player->color = cub->tab_textures[2][cub->so.height * player->texy
			+ player->texx];
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x *
			4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x *
			4) = player->y < player->drawstart ? mlx_get_color_value(
				cub->mlx_ptr, cub->f.color) :
				mlx_get_color_value(cub->mlx_ptr, cub->c.color);
		}
	}
}

void	side_3(t_cub3d *cub, t_player *player)
{
	player->texx = (int)(player->wallx * (double)cub->we.width);
	player->texx = cub->we.width - player->texx - 1;
	player->step = 1.0 * cub->we.height / player->lineheight;
	player->texpos = (player->drawstart - cub->height /
		2 + player->lineheight / 2) * player->step;
	while (++player->y < cub->height)
	{
		if (player->y >= player->drawstart && player->y <= player->drawend)
		{
			player->texy = (int)player->texpos & (cub->we.height - 1);
			player->texpos += player->step;
			player->color = cub->tab_textures[3][cub->we.height
			* player->texy + player->texx];
			*(int*)(cub->img_ptr + player->y * 4 *
			cub->width + player->x * 4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x *
			4) = player->y < player->drawstart ? mlx_get_color_value(
				cub->mlx_ptr, cub->f.color) :
				mlx_get_color_value(cub->mlx_ptr, cub->c.color);
		}
	}
}
