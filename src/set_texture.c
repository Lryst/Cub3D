#include "../cub3d.h"

void    tab_to_adr(t_texture *tex)
{
    int a;
    int b;
    int c;

    a = 0;
    b = 0;
    c = 0;
    if (!(tex->tab_adr = (int**)malloc(sizeof(int*) * tex->height)))
        return;
    while (a < tex->height)
    {
        b = 0;
        if (!(tex->tab_adr[a] = (int*)malloc(sizeof(int) * tex->width)))
            return;
        while (b < tex->width)
        {
            tex->tab_adr[a][b] = tex->iadr[c];
            c++;
            b++;
        }
        a++;
    }
}

void    get_inf(t_texture *tex, void *mlx_ptr)
{
    //tex->path = ""
    printf("coucou 5\n");
    tex->texture = mlx_xpm_file_to_image(mlx_ptr, tex->path, &tex->width, &tex->height);
    printf("coucou 6\n");
    tex->adr = mlx_get_data_addr(tex->texture, &tex->bits_per_pixel, &tex->size_line, &tex->endian);
    printf("coucou 7\n");
    tex->iadr = (int*)tex->adr;
    tab_to_adr(tex);
    printf("coucou 8\n");
}

void    set_img(t_cub3d *cub)
{
    cub->no.path != NULL ? get_inf(&cub->no, cub->mlx_ptr) : 0;
    cub->ea.path != NULL ? get_inf(&cub->ea, cub->mlx_ptr) : 0;
    cub->we.path != NULL ? get_inf(&cub->we, cub->mlx_ptr) : 0;
    cub->so.path != NULL ? get_inf(&cub->so, cub->mlx_ptr) : 0;
}