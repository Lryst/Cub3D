/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:16:58 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:11:21 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_plan(t_cub3d *cub, t_player *player)
{
	player->lineheight = (int)(cub->height / player->perpwalldist);
	player->drawstart = -player->lineheight / 2 + cub->height / 2;
	if (player->drawstart < 0)
		player->drawstart = 0;
	player->drawend = player->lineheight / 2 + cub->height / 2;
	if (player->drawend >= cub->height)
		player->drawend = cub->height - 1;
	if (player->side == 0 || player->side == 2)
		player->wallx = player->posy + player->perpwalldist * player->raydiry;
	else
		player->wallx = player->posx + player->perpwalldist * player->raydirx;
	player->wallx -= floor((player->wallx));
	if (player->side == 0)
		side_0(cub, player);
	if (player->side == 2)
		side_2(cub, player);
	if (player->side == 1)
		side_1(cub, player);
	if (player->side == 3)
		side_3(cub, player);
}

void	draw_sprite(t_cub3d *cub, t_player *player, double *zbuffer)
{
	int d;

	cub->map.sprite.texx = (int)((256 * (cub->map.sprite. drawstartx -
			(cub->map.sprite.screenx - cub->map.sprite.width / 2)) *
			cub->s.width / cub->map.sprite.width) / 256);
	cub->map.sprite. drawstarty = cub->height / 2 - cub->map.sprite.height / 2;
	if (cub->map.sprite. drawstarty < 0)
		cub->map.sprite. drawstarty = 0;
	while (cub->map.sprite. drawstarty < cub->map.sprite.drawendy &&
		cub->map.sprite.transy > 0 && cub->map.sprite. drawstartx > 0 &&
		cub->map.sprite. drawstartx < cub->width &&
		cub->map.sprite.transy < zbuffer[cub->map.sprite. drawstartx])
	{
		d = 256 * cub->map.sprite. drawstarty - cub->height * 128 +
		cub->map.sprite.height * 128;
		cub->map.sprite.texy = ((d * cub->s.height) / cub->map.sprite.height) /
		256;
		player->color = cub->tab_textures[4][cub->s.width *
		cub->map.sprite.texy + cub->map.sprite.texx];
		if ((player->color & 0x00FFFFFF) != 0)
			*(int*)(cub->img_ptr + cub->map.sprite. drawstarty * 4 * cub->width
			+ cub->map.sprite. drawstartx * 4) = player->color;
		cub->map.sprite. drawstarty++;
	}
}
