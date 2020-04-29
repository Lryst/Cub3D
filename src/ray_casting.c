#include "../cub3d.h"

void    ray_caster(t_cub3d *cub, t_player *player)
{
	int x;
	int y;
	double wallX;
	int texX;
	int **texture;
	int buffer[cub->height][cub->width];
	
	x = -1;
	y = -1;
	while (++x < cub->width)
	{
		y = -1;
		//printf("coucou ok on est pas si nulle\n");
		player->camerax = 2 * x / (double)cub->width - 1;
		player->rayDirx = player->dirX + player->planeX * player->camerax;
		player->rayDiry = player->dirY + player->planeY * player->camerax;
		player->mapx = (int)player->posX;
		player->mapy = (int)player->posY;
		player->deltaDistx = ABS(1 / player->rayDirx);
		player->deltaDisty = ABS(1 / player->rayDiry);
		//player->perpWallDist;
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
			cub->closed_map[player->mapx][player->mapy] != '.' ? player->hit = 1 : 0;
		}
		//Calculate distance projected on camera dir
		if(player->side == 0)
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

		//int texNum = cub->closed_map[player->mapx][player->mapy] -1;
		if (player->side == 0)
			wallX = player->posY + player->perpWallDist * player->rayDiry;
		else
			wallX = player->posX + player->perpWallDist * player->rayDirx;
		wallX -= floor((wallX));
		texX = (int)(wallX * (double)64);
		if (player->side == 0 && player->rayDirx > 0)
			texX = 64 - texX - 1;
		if (player->side == 1 && player->rayDiry < 0)
			texX = 64 - texX - 1;
		double step = 1.0 * 64 / player->lineHeight;
		double texPos = (player->drawStart - cub->height / 2 + player->lineHeight / 2) * step;

		while (++y < cub->height)
		{
			//printf("coucou pouet !\n");
			if (y >= player->drawStart && y <= player->drawEnd)
			{
				int texY = (int)texPos & (64 - 1);
				texPos+= step;
				player->color = cub->tab_textures[0][64 * texY + texX];
				buffer[y][x] = player->color;
				//char *dest = cub->no.adr + (y * 64 + x * (cub->no.bits_per_pixel / 8));
				//player->color = *(int*)dest;
				*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = buffer[y][x];
			}
			else
			{
				*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = y < player->drawStart ? 0x33D1FF : 0x0BB62F;
			}
		}
	}
	
}