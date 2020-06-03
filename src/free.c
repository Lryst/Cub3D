#include "../cub3d.h"

void	free_double_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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

void	ft_error(char *str)
{
	int i;

	i = ft_strlen(str);
	write(1, "\n------>   ", 11);
	write(1, str, i);
	write(1, "   <------\n\n", 12);
	system("leaks Cub3D");
	exit(EXIT_FAILURE);
}

int	close_prog(t_cub3d *cub)
{
	mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	system("leaks Cub3D");
	exit(EXIT_SUCCESS);
	return(0);
}