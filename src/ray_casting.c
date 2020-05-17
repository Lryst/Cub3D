#include "../cub3d.h"

void    ray_caster(t_cub3d *cub, t_player *player)
{
	int x;
	int y;
	int a;
	double wallX;
	int texX;
	int **texture;
	double zbuffer[cub->width];
	int *spriteOrder;
	double *spriteDistance;
	int buffer[cub->height][cub->width];
	
	x = -1;
	y = -1;
	while (++x < cub->width)
	{
		y = -1;
		player->camerax = 2 * x / (double)cub->width - 1;
		player->rayDirx = player->dirX + player->planeX * player->camerax;
		player->rayDiry = player->dirY + player->planeY * player->camerax;
		player->mapx = (int)player->posX;
		player->mapy = (int)player->posY;
		player->deltaDistx = sqrt(1 + (player->rayDiry * player->rayDiry) / (player->rayDirx * player->rayDirx));
		player->deltaDisty = sqrt(1 + (player->rayDirx * player->rayDirx) / (player->rayDiry * player->rayDiry));
		player->hit = 0;
		if (player->rayDirx < 0)
		{
			player->stepx = -1;
			player->sideDistx = (player->posX - player->mapx) * player->deltaDistx;
		}
		else
		{
			player->stepx = 1;
			player->sideDistx = (player->mapx + 1.0 - player->posX) * player->deltaDistx;
		}
		if(player->rayDiry < 0)
		{
			//printf("POUET\n");
			player->stepy = -1;
			player->sideDisty = (player->posY - player->mapy) * player->deltaDisty;
		}
		else
		{
			player->stepy = 1;
			player->sideDisty = (player->mapy + 1.0 - player->posY) * player->deltaDisty;
		}
		while (player->hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(player->sideDistx < player->sideDisty)
			{
				player->sideDistx += player->deltaDistx;
				player->mapx += player->stepx;
				player->side = 0;
			}
			else
			{
				player->sideDisty += player->deltaDisty;
				player->mapy += player->stepy;
				player->side = 1;
			}
			//Check if ray has hit a wall
			cub->map.line[player->mapx][player->mapy] == '1' ? player->hit = 1 : 0;
		}
		if (player->side == 1)
		{
			if (player->rayDiry < 0)
				player->side += 2;
		}
		else
		{
			if (player->rayDirx < 0)
				player->side += 2;
		}
		//Calculate distance projected on camera dir
		if(player->side == 0 || player->side == 2)
			player->perpWallDist = (player->mapx - player->posX + (1 - player->stepx) / 2) / player->rayDirx;
      	else
			player->perpWallDist = (player->mapy - player->posY + (1 - player->stepy) / 2) / player->rayDiry;
		
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
			wallX = player->posY + player->perpWallDist * player->rayDiry;
		else
			wallX = player->posX + player->perpWallDist * player->rayDirx;
		wallX -= floor((wallX));
		if (player->side == 0)
		{
			texX = (int)(wallX * (double)cub->no.width);
			texX = cub->no.width - texX - 1;double step = 1.0 * cub->no.height / player->lineHeight;
			double texPos = (player->drawStart - cub->height / 2 + player->lineHeight / 2) * step;

			while (++y < cub->height)
			{
				if (y >= player->drawStart && y <= player->drawEnd)
				{
					int texY = (int)texPos & (cub->no.height - 1);
					texPos+= step;
					player->color = cub->tab_textures[0][cub->no.height * texY + texX];
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = player->color;
				}
				else
				{
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = y < player->drawStart ? 0x33D1FF : 0x0BB62F;
				}
			}
		}
		if (player->side == 2)
		{
			texX = (int)(wallX * (double)cub->so.width);
			texX = cub->so.width - texX - 1;
			double step = 1.0 * cub->so.height / player->lineHeight;
			double texPos = (player->drawStart - cub->height / 2 + player->lineHeight / 2) * step;

			while (++y < cub->height)
			{
				if (y >= player->drawStart && y <= player->drawEnd)
				{
					int texY = (int)texPos & (cub->so.height - 1);
					texPos+= step;
					player->color = cub->tab_textures[2][cub->so.height * texY + texX];
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = player->color;
				}
				else
				{
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = y < player->drawStart ? 0x33D1FF : 0x0BB62F;
				}
			}
		}
		if (player->side == 1)
		{
			texX = (int)(wallX * (double)cub->ea.width);
			texX = cub->ea.width - texX - 1;
			double step = 1.0 * cub->ea.height / player->lineHeight;
			double texPos = (player->drawStart - cub->height / 2 + player->lineHeight / 2) * step;

			while (++y < cub->height)
			{
				if (y >= player->drawStart && y <= player->drawEnd)
				{
					int texY = (int)texPos & (cub->ea.height - 1);
					texPos+= step;
					player->color = cub->tab_textures[1][cub->ea.height * texY + texX];
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = player->color;
				}
				else
				{
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = y < player->drawStart ? 0x33D1FF : 0x0BB62F;
				}
			}
		}
		if (player->side == 3)
		{
			texX = (int)(wallX * (double)cub->we.width);
			texX = cub->we.width - texX - 1;
			double step = 1.0 * cub->we.height / player->lineHeight;
			double texPos = (player->drawStart - cub->height / 2 + player->lineHeight / 2) * step;

			while (++y < cub->height)
			{
				if (y >= player->drawStart && y <= player->drawEnd)
				{
					int texY = (int)texPos & (cub->we.height - 1);
					texPos+= step;
					player->color = cub->tab_textures[3][cub->we.height * texY + texX];
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = player->color;
				}
				else
				{
					*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = y < player->drawStart ? 0x33D1FF : 0x0BB62F;
				}
			}
		}
		zbuffer[x] = player->perpWallDist;
	}
	int i;
	int b;

	i = 0;
	spriteOrder = (int*)malloc(sizeof(int) * cub->map.sprite.sprite_nbr);
	spriteDistance = (double*)malloc(sizeof(double) * cub->map.sprite.sprite_nbr);
	while (i < cub->map.sprite.sprite_nbr)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((player->posX - cub->map.sprite.pos_sprite[i][0]) * (player->posX - cub->map.sprite.pos_sprite[i][0]) + (player->posY - cub->map.sprite.pos_sprite[i][1]) * (player->posY - cub->map.sprite.pos_sprite[i][1]));
		i++;
	}
	double stock_d;
	int stock;
	i = 0;
	while (i < cub->map.sprite.sprite_nbr)
	{
		if (i + 1 < cub->map.sprite.sprite_nbr && spriteDistance[i] < spriteDistance[i + 1])
		{
			stock = spriteOrder[i + 1];
			stock_d = spriteDistance[i + 1];
			spriteOrder[i + 1] = spriteOrder[i];
			spriteDistance[i + 1] = spriteDistance[i];
			spriteOrder[i] = stock;
			spriteDistance[i] = stock_d;
			i = -1;
		}
		i++;
	}

	i = 0;
	while (i < cub->map.sprite.sprite_nbr)
	{
		//printf("order [%d], distance [%f]\n", spriteOrder[i], spriteDistance[i]);
		i++;
	}

	i = 0;
	while (i < cub->map.sprite.sprite_nbr)
	{
		
		cub->map.sprite.x = cub->map.sprite.pos_sprite[spriteOrder[i]][0] - player->posX + 0.5;
		cub->map.sprite.y = cub->map.sprite.pos_sprite[spriteOrder[i]][1] - player->posY + 0.5;

		cub->map.sprite.inDet = 1.0 / (player->planeX * player->dirY - player->dirX * player->planeY);

		cub->map.sprite.transX = cub->map.sprite.inDet * (player->dirY * cub->map.sprite.x - player->dirX * cub->map.sprite.y);
		cub->map.sprite.transY = cub->map.sprite.inDet * (-player->planeY * cub->map.sprite.x + player->planeX * cub->map.sprite.y);
		cub->map.sprite.screenX = (int)((cub->width / 2) * (1 + cub->map.sprite.transX / cub->map.sprite.transY));

		cub->map.sprite.height = abs((int)(cub->height / (cub->map.sprite.transY)));
		cub->map.sprite.drawstartY = -cub->map.sprite.height / 2 + cub->height / 2;
		if (cub->map.sprite.drawstartY < 0)
			cub->map.sprite.drawstartY = 0;
		cub->map.sprite.drawendY = cub->map.sprite.height / 2 + cub->height / 2;
		if (cub->map.sprite.drawendY >= cub->height)
			cub->map.sprite.drawendY = cub->height - 1;
		
		
		cub->map.sprite.width = abs((int)(cub->height / (cub->map.sprite.transY)));
		cub->map.sprite.drawstartX = - cub->map.sprite.width / 2 + cub->map.sprite.screenX;
		if (cub->map.sprite.drawstartX < 0)
			cub->map.sprite.drawstartX = 0;
		cub->map.sprite.drawendX = cub->map.sprite.width / 2 + cub->map.sprite.screenX;
		if (cub->map.sprite.drawendX >= cub->width)
			cub->map.sprite.drawendX = cub->width - 1;
		while (cub->map.sprite.drawstartX < cub->map.sprite.drawendX)
		{
			cub->map.sprite.texX = (int)((256 * (cub->map.sprite.drawstartX - (cub->map.sprite.screenX - cub->map.sprite.width / 2 )) * cub->s.width / cub->map.sprite.width) / 256);
			cub->map.sprite.drawstartY = cub->height / 2 - cub->map.sprite.height / 2;
			if (cub->map.sprite.drawstartY < 0)
				cub->map.sprite.drawstartY = 0;
			while (cub->map.sprite.drawstartY < cub->map.sprite.drawendY && cub->map.sprite.transY > 0 && cub->map.sprite.drawstartX > 0 && cub->map.sprite.drawstartX < cub->width && cub->map.sprite.transY < zbuffer[cub->map.sprite.drawstartX])
			{
				int d = 256 * cub->map.sprite.drawstartY - cub->height * 128 + cub->map.sprite.height * 128;
				cub->map.sprite.texY = ((d * cub->s.height) / cub->map.sprite.height) / 256;
				player->color = cub->tab_textures[4][cub->s.width * cub->map.sprite.texY + cub->map.sprite.texX];
				if ((player->color & 0x00FFFFFF) != 0)
				{
					*(int*)(cub->img_ptr + cub->map.sprite.drawstartY * 4 * cub->width + cub->map.sprite.drawstartX * 4) = player->color;
				}
				cub->map.sprite.drawstartY++;
			}
			cub->map.sprite.drawstartX++;
		}
		i++;
	}
}