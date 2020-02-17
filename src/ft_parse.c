/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/02/17 19:08:31 by lryst            ###   ########.fr       */
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

void	separate_texture(char **tab, t_cub3d *ptr)
{
	int i;

	i = 0;
	if (ft_strcmp("NO", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			ptr->no.path = ft_strdup(tab[i + 1]);
		ft_printf("NO %s\n", ptr->no.path);
	}
	if (ft_strcmp("SO", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			ptr->so.path = ft_strdup(tab[i + 1]);
		ft_printf("SO %s\n", ptr->so.path);
	}
	if (ft_strcmp("WE", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			ptr->we.path = ft_strdup(tab[i + 1]);
		ft_printf("we %s\n", ptr->we.path);
	}
	if (ft_strcmp("EA", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			ptr->ea.path = ft_strdup(tab[i + 1]);
		ft_printf("EA %s\n", ptr->ea.path);
	}
	if (ft_strcmp("S", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			ptr->s.path = ft_strdup(tab[i + 1]);
		ft_printf("S %s\n", ptr->s.path);
	}
}

void	check_color(char **tab, t_cub3d *ptr)
{
	int i;
	int a;
	char **color = NULL;

	i = 0;
	a = 0;
	if (ft_strcmp("F", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			color = ft_split(tab[i + 1],',');
			if (ft_atoi(color[a]) > -1 && ft_atoi(color[a]) < 256)
			{
				if (ft_atoi(color[a + 1]) > -1 && ft_atoi(color[a + 1]) < 256)
				{
					if (ft_atoi(color[a + 1]) > -1 && ft_atoi(color[a + 1]) < 256)
					{
						ptr->f.red = ft_atoi(color[a]);
						ptr->f.green = ft_atoi(color[a + 1]);
						ptr->f.blue = ft_atoi(color[a + 2]);
					}
				}
			}
		}
		free(*color);
		*color = NULL;
		ft_printf("F.red %d\n", ptr->f.red);
		ft_printf("F.green %d\n", ptr->f.green);
		ft_printf("F.blue %d\n", ptr->f.blue);
	}
	//ft_printf("F %s\n", ptr->f);
}

void	parse_line(char *line, t_cub3d *ptr)
{
	char **tab;
	
	tab = ft_split((const char*)line, ' ');
	separate_r(tab, ptr);
	separate_texture(tab, ptr);
	check_color(tab, ptr);
	free (*tab);
	*tab = NULL;
	// int i;
	// i = -1;
	// ft_printf("\n---------\n");
	// while (tab[++i])
	// 	ft_printf("->%s<- ", tab[i]);

}

/*void	free_struct(t_cub3d *ptr)
{
	ptr->width != 0 ? free(ptr->width) : ptr->width;
	ptr->height != 0 ? free(ptr->height) : ptr->height;
	//ptr->width != NULL ? free(ptr->width) : ptr->width;		
}*/

void	parsing(int fd)
{
	t_cub3d ptr;
	char *line;
	int i;

	line = NULL;
	i = 0;
	init_cub3d(&ptr);
	if (get_next_line(fd, &line) == 1)
	{
		parse_line(line, &ptr);
		free(line);
		line = NULL;
		i++;
	}
	//free_struct(&ptr);
}

/*int i;
	i = -1;
	ft_printf("\n---------\n");
	while (tab[++i])
		ft_printf("->%s<- ", tab[i]);*/