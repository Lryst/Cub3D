#include "../cub3d.h"

void    get_inf(t_texture *tex, void *mlx_ptr, int **tab)
{
    if (mlx_ptr == NULL || tex->texture != NULL)
    {
        ft_printf("mlx_ptr ou/et tex->texture : == NULL ou/et tex->texture != NULL\n");
    }
    tex->texture = mlx_xpm_file_to_image(mlx_ptr, tex->path, &tex->width, &tex->height);
    *tab = (int*) mlx_get_data_addr(tex->texture, &tex->bits_per_pixel, &tex->size_line, &tex->endian);
}

void    set_img(t_cub3d *cub)
{
    if (cub->no.path != NULL)
        get_inf(&cub->no, cub->mlx_ptr, &cub->tab_textures[0]);
    if (cub->ea.path != NULL)
        get_inf(&cub->ea, cub->mlx_ptr, &cub->tab_textures[1]);
    if (cub->we.path != NULL)
        get_inf(&cub->so, cub->mlx_ptr, &cub->tab_textures[2]);
    if (cub->so.path != NULL)
        get_inf(&cub->we, cub->mlx_ptr, &cub->tab_textures[3]);
    if (cub->s.path != NULL)
        get_inf(&cub->s, cub->mlx_ptr, &cub->tab_textures[4]);
}