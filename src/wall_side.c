#include "../cub3d.h"

void    side_0(t_cub3d *cub, t_player *player)
{
    int texX;
    double step;
    double texPos;
    texX = (int)(player->wallX * (double)cub->no.width);
    texX = cub->no.width - texX - 1;
    step = 1.0 * cub->no.height / player->lineHeight;
    texPos = (player->drawStart - cub->height / 2 + player->lineHeight / 2) * step;

    while (++player->y < cub->height)
    {
        if (player->y >= player->drawStart && player->y <= player->drawEnd)
        {
            int texY = (int)texPos & (cub->no.height - 1);
            texPos+= step;
            player->color = cub->tab_textures[0][cub->no.height * texY + texX];
            *(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = player->color;
        }
        else
        {
            *(int*)(cub->img_ptr + player->y * 4 * cub->width + player->x * 4) = player->y < player->drawStart ? 0x33D1FF : 0x0BB62F;
        }
    }
}