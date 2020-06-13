/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:52 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 22:18:15 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int		main(int ac, char **av)
{
	t_cub3d	cub;
	int		fd;

	if (ac < 2 || ac > 3)
		ft_error("bad nbr argument");
	if (check_is_ptcub(av[1], ".cub") == 0)
		ft_error(" the first argument is not a .cub");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("bad file descriptor");
	init_cub3d(&cub);
	cub.save = 0;
	check_args(&cub, ac, av, fd);
	ft_error("bad arguments");
}
