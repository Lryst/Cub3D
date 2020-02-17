/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/02/17 13:44:55 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_cub3d(t_cub3d *ptr)
{
	ft_bzero(ptr, sizeof(t_cub3d));
}

void	separate_r(char **tab, t_cub3d *ptr)
{
	int i;

	i = 0;
	if (ft_strcmp("R", (const char*)tab[i]) == 0)
	{
		if (tab[i + 1] != NULL && tab[i + 2] != NULL && tab[i + 3] == NULL)
		{
			if (tab[i + 1] > 0 && tab[i + 2] > 0 && tab[i + 3] == NULL)
			{
				ptr->width = ft_atoi(tab[i + 1]);
				ptr->height= ft_atoi(tab[i + 2]);
			}
		}
		ft_printf("W %d\n", ptr->width);
		ft_printf("H %d\n", ptr->height);
	}
}

void	check_texture(char **tab, t_cub3d *ptr)
{
	int i;

	i = 0;
	if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		ptr->no.path = ft_strdup(tab[i + 1]);
}

void	separate_texture(char **tab, t_cub3d *ptr)
{
	int i;

	i = 0;
	if (ft_strcmp("NO", (const char *)tab[i]) == 0)
	{
		check_texture(tab, ptr);
		ft_printf("NO %s\n", ptr->no.path);
	}
	if (ft_strcmp("SO", (const char *)tab[i]) == 0)
	{
		check_texture(tab, ptr);
		ft_printf("SO %s\n", ptr->so.path);
	}
	if (ft_strcmp("we", (const char *)tab[i]) == 0)
	{
		check_texture(tab, ptr);
		ft_printf("we %s\n", ptr->we.path);
	}
	if (ft_strcmp("EA", (const char *)tab[i]) == 0)
	{
		check_texture(tab, ptr);
		ft_printf("EA %s\n", ptr->ea.path);
	}		
}

void	parse_line(char *line, t_cub3d *ptr)
{
	char **tab;
	
	tab = ft_split((const char*)line, ' ');
	separate_r(tab, ptr);
	separate_texture(tab, ptr);
	// int i;
	// i = -1;
	// ft_printf("\n---------\n");
	// while (tab[++i])
	// 	ft_printf("->%s<- ", tab[i]);

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