#include "../Cub3D.h"

void	check_dist_sprite(t_cub3d *cub, t_player *player)
{
	int i;

	i = 0;
	player->s_order = (int*)malloc(sizeof(int) * cub->map.sprite.sprite_nbr);
	player->s_dist = (double*)malloc(sizeof(double) * cub->map.sprite.sprite_nbr);
	while (i < cub->map.sprite.sprite_nbr)
	{
		player->s_order[i] = i;
		player->s_dist[i] = ((player->posX - cub->map.sprite.pos_sprite[i][0])
		 * (player->posX - cub->map.sprite.pos_sprite[i][0]) + (player->posY -
		  cub->map.sprite.pos_sprite[i][1]) *
		   (player->posY - cub->map.sprite.pos_sprite[i][1]));
		i++;
	}
}

void	sort_sprite(t_cub3d*cub, t_player *player)
{
	int i;
	int stock;
	int stock_d;

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
}

void	init_sprite_2(t_cub3d *cub)
{
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
}

void	init_sprite(t_cub3d *cub, t_player *player)
{
	cub->map.sprite.inDet = 1.0 / (player->planeX * player->dirY - player->dirX * player->planeY);

	cub->map.sprite.transX = cub->map.sprite.inDet * (player->dirY * 
				cub->map.sprite.x - player->dirX * cub->map.sprite.y);
	cub->map.sprite.transY = cub->map.sprite.inDet * (-player->planeY * 
				cub->map.sprite.x + player->planeX * cub->map.sprite.y);
	cub->map.sprite.screenX = (int)((cub->width / 2) * 
		(1 + cub->map.sprite.transX / cub->map.sprite.transY));
	init_sprite_2(cub);
}

void	gestion_sprite(t_cub3d *cub, t_player *player, double *zbuffer)
{
	int i;
	
	i = 0;
	check_dist_sprite(cub, player);
	sort_sprite(cub, player);
	while (i < cub->map.sprite.sprite_nbr)
	{
		cub->map.sprite.x = cub->map.sprite.pos_sprite[player->s_order[i]][0] - player->posX + 0.5;
		cub->map.sprite.y = cub->map.sprite.pos_sprite[player->s_order[i]][1] - player->posY + 0.5;
		init_sprite(cub,player);
		while (cub->map.sprite.drawstartX < cub->map.sprite.drawendX)
		{
			draw_sprite(cub, player, zbuffer);
			cub->map.sprite.drawstartX++;
		}
		i++;
	}
	free(player->s_order);
	free(player->s_dist);
}
