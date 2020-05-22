#include "../cub3d.h"

void	free_double_tab(char **str)
{
	int i;

	i = 0;
	while(str[i])
		printf("str[%d] = [%s]\n", i, str[i]);
}

void	free_tex(t_texture *tex)
{
	free(tex->texture);
	free(tex->adr);
	free(tex->path);
	free(tex->iadr);
}

void	free_void(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	close_prog(t_cub3d *cub)
{
	free_void(cub->mlx_ptr);
	free_void(cub->win_ptr);
	free_void(cub->img);
	free_void(cub->img_ptr);
	free_tex(&cub->no);
	free_tex(&cub->so);
	free_tex(&cub->ea);
	free_tex(&cub->we);
}