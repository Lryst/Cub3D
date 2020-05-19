#include "../cub3d.h"

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

void 	check_wall_hit_2(t_cub3d *cub, t_player *player)
{
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
	draw_plan(cub, player);
}

void	check_wall_hit(t_cub3d *cub, t_player *player)
{
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
	check_wall_hit_2(cub,player);
}


void	get_side_dist(t_cub3d *cub, t_player *player)
{
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
	check_wall_hit(cub, player);
}

void	init_raycasting(t_cub3d *cub, t_player *player)
{
	player->y = -1;
	player->camerax = 2 * player->x / (double)cub->width - 1;
	player->rayDirx = player->dirX + player->planeX * player->camerax;
	player->rayDiry = player->dirY + player->planeY * player->camerax;
	player->mapx = (int)player->posX;
	player->mapy = (int)player->posY;
	player->deltaDistx = sqrt(1 + (player->rayDiry * player->rayDiry) / (player->rayDirx * player->rayDirx));
	player->deltaDisty = sqrt(1 + (player->rayDirx * player->rayDirx) / (player->rayDiry * player->rayDiry));
	player->hit = 0;
	get_side_dist(cub, player);
}

void    start_ray_casting(t_cub3d *cub, t_player *player)
{
	double zbuffer[cub->width];
	
	player->x = -1;
	player->y = -1;
	while (++player->x < cub->width)
	{
		init_raycasting(cub, player);
		zbuffer[player->x] = player->perpWallDist;
	}
	int i;
	int b;

	i = 0;
	player->s_order = (int*)malloc(sizeof(int) * cub->map.sprite.sprite_nbr);
	player->s_dist = (double*)malloc(sizeof(double) * cub->map.sprite.sprite_nbr);
	while (i < cub->map.sprite.sprite_nbr)
	{
		player->s_order[i] = i;
		player->s_dist[i] = ((player->posX - cub->map.sprite.pos_sprite[i][0]) * (player->posX - cub->map.sprite.pos_sprite[i][0]) + (player->posY - cub->map.sprite.pos_sprite[i][1]) * (player->posY - cub->map.sprite.pos_sprite[i][1]));
		i++;
	}
	double stock_d;
	int stock;
	i = 0;
	while (i < cub->map.sprite.sprite_nbr)
	{
		if (i + 1 < cub->map.sprite.sprite_nbr && player->s_dist[i] < player->s_dist[i + 1])
		{
			stock = player->s_order[i + 1];
			stock_d = player->s_dist[i + 1];
			player->s_order[i + 1] = player->s_order[i];
			player->s_dist[i + 1] = player->s_dist[i];
			player->s_order[i] = stock;
			player->s_dist[i] = stock_d;
			i = -1;
		}
		i++;
	}
	i = 0;
	while (i < cub->map.sprite.sprite_nbr)
	{
		cub->map.sprite.x = cub->map.sprite.pos_sprite[player->s_order[i]][0] - player->posX + 0.5;
		cub->map.sprite.y = cub->map.sprite.pos_sprite[player->s_order[i]][1] - player->posY + 0.5;

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