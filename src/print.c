#include "../Cub3D.h"

void	draw_plan(t_cub3d *cub, t_player *player)
{
	//Calculate height of line to draw on screen
	player->lineHeight = (int)(cub->height / player->perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	player->drawStart = -player->lineHeight / 2 + cub->height / 2;
	if(player->drawStart < 0)
		player->drawStart = 0;
	player->drawEnd = player->lineHeight / 2 + cub->height / 2;
	if(player->drawEnd >= cub->height)
		player->drawEnd = cub->height - 1;
	if (player->side == 0 || player-> side == 2)
		player->wallX = player->posY + player->perpWallDist * player->rayDiry;
	else
		player->wallX = player->posX + player->perpWallDist * player->rayDirx;
	player->wallX -= floor((player->wallX));
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
	cub->map.sprite.texX = (int)((256 * (cub->map.sprite.drawstartX - 
			(cub->map.sprite.screenX - cub->map.sprite.width / 2 )) * 
			cub->s.width / cub->map.sprite.width) / 256);
	cub->map.sprite.drawstartY = cub->height / 2 - cub->map.sprite.height / 2;
	if (cub->map.sprite.drawstartY < 0)
		cub->map.sprite.drawstartY = 0;
	while (cub->map.sprite.drawstartY < cub->map.sprite.drawendY &&
		cub->map.sprite.transY > 0 && cub->map.sprite.drawstartX > 0 &&
		cub->map.sprite.drawstartX < cub->width &&
		cub->map.sprite.transY < zbuffer[cub->map.sprite.drawstartX])
	{
		int d = 256 * cub->map.sprite.drawstartY - cub->height * 128 + cub->map.sprite.height * 128;
		cub->map.sprite.texY = ((d * cub->s.height) / cub->map.sprite.height) / 256;
		player->color = cub->tab_textures[4][cub->s.width * cub->map.sprite.texY + cub->map.sprite.texX];
		if ((player->color & 0x00FFFFFF) != 0)
		{
			*(int*)(cub->img_ptr + cub->map.sprite.drawstartY * 4 * cub->width
				 + cub->map.sprite.drawstartX * 4) = player->color;
		}
		cub->map.sprite.drawstartY++;
	}
}
