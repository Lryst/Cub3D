#include "../cub3d.h"

void	side_0(t_cub3d *cub, t_player *player)
{
	player->texX = (int)(player->wallX * (double)cub->no.width);
	player->texX = cub->no.width - player->texX - 1;
	player->step = 1.0 * cub->no.height / player->lineHeight;
	player->texPos = (player->drawStart - cub->height / 
	2 + player->lineHeight / 2) * player->step;

	while (++player->y < cub->height)
	{
		if (player->y >= player->drawStart && player->y <= player->drawEnd)
		{
			player->texY = (int)player->texPos & (cub->no.height - 1);
			player->texPos+= player->step;
			player->color = cub->tab_textures[0][cub->no.height * player->texY + player->texX];
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = 
				player->y < player->drawStart ? 0x33D1FF : 0x0BB62F;
		}
	}
}

void	side_1(t_cub3d *cub, t_player *player)
{
	player->texX = (int)(player->wallX * (double)cub->ea.width);
	player->texX = cub->ea.width - player->texX - 1;
	player->step = 1.0 * cub->ea.height / player->lineHeight;
	player->texPos = (player->drawStart - cub->height / 
		2 + player->lineHeight / 2) * player->step;

	while (++player->y < cub->height)
	{
		if (player->y >= player->drawStart && player->y <= player->drawEnd)
		{
			player->texY = (int)player->texPos & (cub->ea.height - 1);
			player->texPos+= player->step;
			player->color = cub->tab_textures[1][cub->ea.height * player->texY + player->texX];
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = 
				player->y < player->drawStart ? 0x33D1FF : 0x0BB62F;
		}
	}
}

void	side_2(t_cub3d *cub, t_player* player)
{
	player->texX = (int)(player->wallX * (double)cub->so.width);
	player->texX = cub->so.width - player->texX - 1;
	player->step = 1.0 * cub->so.height / player->lineHeight;
	player->texPos = (player->drawStart - cub->height /
		 2 + player->lineHeight / 2) * player->step;

	while (++player->y < cub->height)
	{
		if (player->y >= player->drawStart && player->y <= player->drawEnd)
		{
			player->texY = (int)player->texPos & (cub->so.height - 1);
			player->texPos+= player->step;
			player->color = cub->tab_textures[2][cub->so.height * player->texY + player->texX];
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = 
				player->y < player->drawStart ? 0x33D1FF : 0x0BB62F;
		}
	}
}

void	side_3(t_cub3d *cub, t_player* player)
{
	player->texX = (int)(player->wallX * (double)cub->we.width);
	player->texX = cub->we.width - player->texX - 1;
	player->step = 1.0 * cub->we.height / player->lineHeight;
	player->texPos = (player->drawStart - cub->height / 
		2 + player->lineHeight / 2) * player->step;

	while (++player->y < cub->height)
	{
		if (player->y >= player->drawStart && player->y <= player->drawEnd)
		{
			player->texY = (int)player->texPos & (cub->we.height - 1);
			player->texPos+= player->step;
			player->color = cub->tab_textures[3][cub->we.height 
			* player->texY + player->texX];
			*(int*)(cub->img_ptr + player->y * 4 * 
			cub->width + player->x * 4) = player->color;
		}
		else
		{
			*(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) =
			 player->y < player->drawStart ? 0x33D1FF : 0x0BB62F;
		}
	}
}