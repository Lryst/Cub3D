/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:11:10 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 22:13:48 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	check_screen_size(t_cub3d *cub)
{
	int height;
	int width;

	height = cub->height;
	width = cub->width;
	mlx_get_screen_size(cub->mlx_ptr, &width, &height);
	width < cub->width ? cub->width = width : 0;
	height < cub->height ? cub->height = height : 0;
}

int		check_is_ptcub(char *av, char *file)
{
	int i;
	int j;
	int k;

	i = ft_strlen(av);
	j = ft_strlen(file);
	k = i - j;
	while (i > k)
	{
		if (av[i] != file[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

void	check_args(t_cub3d *cub, int ac, char **av, int fd)
{
	if (ac == 2)
	{
		ft_printf("\n\n--->	START	<---\n\n");
		start_parsing(fd, cub);
		init_position(&cub->player, cub);
		mlx_handle(cub, av[1]);
	}
	if (ac == 3 && ft_strcmp("--save", av[2]) == 0)
	{
		ft_printf("\n\n--->	START	<---\n\n");
		cub->save = 1;
		start_parsing(open(av[1], O_RDONLY), cub);
		init_position(&cub->player, cub);
		mlx_handle(cub, av[1]);
	}
}
