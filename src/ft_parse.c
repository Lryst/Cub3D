/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/02/13 22:01:07 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_cub3d(t_cub3d *ptr)
{
	ft_bzero(ptr, sizeof(t_cub3d));
}

void	parse_line(char *line, t_cub3d *ptr)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split((const char*)line, ' ');
	strcmp('R', tab[i]) == 0 ? 

}

void	parsing(int fd)
{
	t_cub3d ptr;
	char *line;
	int i;

	line = NULL;
	i = 0;
	init_cub3d(&ptr);
	while (get_next_line(fd, &line) == 1)
	{
		parse_line(line, &ptr);
		free(line);
		i++;
	}
}

/*int i;
	i = -1;
	ft_printf("\n---------\n");
	while (tab[++i])
		ft_printf("->%s<- ", tab[i]);*/