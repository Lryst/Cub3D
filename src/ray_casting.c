#include "../cub3d.h"

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
		player->perpWallDist = (player->mapx - player->posX +
			 (1 - player->stepx) / 2) / player->rayDirx;
	else
		player->perpWallDist = (player->mapy - player->posY +
			 (1 - player->stepy) / 2) / player->rayDiry;
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
		cub->closed_map[player->mapx][player->mapy] == '1' ? player->hit = 1 : 0;
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
	player->deltaDistx = sqrt(1 + (player->rayDiry * player->rayDiry)
		 / (player->rayDirx * player->rayDirx));
	player->deltaDisty = sqrt(1 + (player->rayDirx * player->rayDirx)
		 / (player->rayDiry * player->rayDiry));
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
		//printf("cub->height = [%d]\n", cub->height);
		zbuffer[player->x] = player->perpWallDist;
	}
	gestion_sprite(cub, player, zbuffer);
	if (cub->save == 1)
	{
		save(cub);
	}
}
