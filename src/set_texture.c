#include "../cub3d.h"

void    tab_to_adr(t_texture *tex, int **tab)
{
    int a;
    int b;
    int c;

    a = 0;
    b = 0;
    c = 0;
    if (!(tex->tab_adr = (int**)malloc(sizeof(int*) * tex->height)))
        return;
    while (a++ < tex->height)
    {
        b = 0;
        if (!(tex->tab_adr[a] = (int*)malloc(sizeof(int) * tex->width)))
            return;
        while (b < tex->width)
        {
            tex->tab_adr[a][b] = tex->iadr[c];
            //printf("tex->iadr[%d] = {%d}\n", c, tex->iadr[c]);
            c++;
            b++;
        }
    }
    c = -1;
    /*attention il peut y avoir des leaks par rqapport a ce malloc*/
    if (!(*tab = (int*)malloc(sizeof(int) * 4097)))
        return;
    *tab = tex->iadr;
    //printf()
}

void    get_inf(t_texture *tex, void *mlx_ptr, int **tab)
{
    printf("coucou 5\n");
    tex->texture = mlx_xpm_file_to_image(mlx_ptr, tex->path, &tex->width, &tex->height);
    printf("coucou 6\n");
    tex->adr = mlx_get_data_addr(tex->texture, &tex->bits_per_pixel, &tex->size_line, &tex->endian);
    printf("coucou 7\n");
    tex->iadr = (int*)tex->adr;
    tab_to_adr(tex, tab);
    printf("tex->adr {%s}\n", tex->adr);
}

void    set_img(t_cub3d *cub)
{
    if (!(cub->tab_textures = (int**)malloc(sizeof(int) * 4)))
        return;
    if (cub->no.path != NULL)
        get_inf(&cub->no, cub->mlx_ptr, &cub->tab_textures[0]);
    if (cub->ea.path != NULL)
        get_inf(&cub->ea, cub->mlx_ptr, &cub->tab_textures[1]);
    if (cub->we.path != NULL)
        get_inf(&cub->so, cub->mlx_ptr, &cub->tab_textures[2]);
    if (cub->so.path != NULL)
        get_inf(&cub->we, cub->mlx_ptr, &cub->tab_textures[3]);
}