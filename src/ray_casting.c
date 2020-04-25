#include "../cub3d.h"

/* void	put_textures_in_tab(t_cub3d *cub)
{
	int i;
	printf("coucou 34\n");
	if (!(cub->tab_textures = (int**)malloc(sizeof(int*) * 4)))
		return;
	printf("coucou 35\n");
	//printf("1 [%p]\n", cub->tab_textures);
	
	if (!(cub->tab_textures[0] = (int*)malloc(sizeof(int) * 4096)))
		return;
	i = 0;
	while(i++ < 4096)
		cub->tab_textures[0][i] = cub->so.iadr[i];
	printf("coucou 36\n");
	
	
	
	 if (!(cub->tab_textures[1] = (int*)malloc(sizeof(int) * 4096)))
		return;
	i = 0;
	//printf("cub->ea.iadr = {%d}\n", cub->ea.iadr);
	while(i++ < 4096)
		cub->tab_textures[1][i] = cub->ea.iadr[i];
	printf("coucou 37\n");
	
	
	
	if (!(cub->tab_textures[2] = (int*)malloc(sizeof(int) * 4096)))
		return;
	i = 0;
	while(i++ < 4096)
		cub->tab_textures[2][i] = cub->no.iadr[i];
	printf("coucou 38\n");
	
	
	if (!(cub->tab_textures[3] = (int*)malloc(sizeof(int) * 4096)))
		return;
	i = 0;
	while(i++ < 4096)
		cub->tab_textures[3][i] = cub->we.iadr[i]; 
} */

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
	//put_textures_in_tab(cub);	
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
		int step = 1 * 64 / player->lineHeight;
		int texPos = (player->drawStart - cub->height / 2 + player->lineHeight / 2) * step;

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
		//printf("on est là\n");
		//double step = 1.0 * 64 / (cub->height - (player->drawStart + player->drawEnd));
		//y = y * step;
		/*write(1, "OK\n", 3);
		cub->no.texture = mlx_xpm_file_to_image (cub->mlx_ptr, cub->no.path, &cub->no.height, &64 );
		//printf("cub->no.path = [%s]\n cub->no.height = [%d]\n cub->no.width = [%d]\n cub->no.texture = [%s]\n", cub->no.path, cub->no.height, cub->no.width, cub->no.texture);
		cub->no.adr = mlx_get_data_addr(cub->no.texture, &cub->no.bits_per_pixel, &cub->no.size_line, &cub->no.endian);

		cub->no.iadr = (int*)cub->no.adr;
		tab_to_adr(&cub->no);*/
		//printf("cub->no.tab_adr[y][x] = {%d}\n", cub->no.tab_adr[y][x]);
		/* while (++y < cub->height)
		{
			if (y >= player->drawStart && y <= player->drawEnd)
			{
				*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = cub->no.tab_adr[0][0];
				//y > 63 ? y = 0 : y++;

				int pixelRepetition = ABS(((player->drawStart - player->drawEnd)) / 64);
				printf("%d\n", pixelRepetition);
				
				k = -1;
				while (j >= player->drawStart && j <= player->drawEnd && ++k != pixelRepetition && j < cub->height) {
					*(int*)(cub->img_ptr + j * 4 * cub->width + i * 4) = cub->no.tab_adr[y][x];
					j++;
				}
				y++;
				if (y > 64)
					y = 0; 
			}
			else
			{
				*(int*)(cub->img_ptr + y * 4 * cub->width + x * 4) = y < player->drawStart ? 0x33D1FF : 0x0BB62F;
			}
		}*/
	}
	
}