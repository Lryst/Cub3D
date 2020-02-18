/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/02/18 18:08:51 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_check_struct(t_check_struct *ret)
{
	ret->width = 0;
	ret->height = 0;
	ret->no = 0;
	ret->so = 0;
	ret->we = 0;
	ret->ea = 0;
	ret->s = 0;
	ret->f = 0;
	ret->c = 0;	
}

void	init_cub3d(t_cub3d *ptr)
{
	ft_bzero(ptr, sizeof(t_cub3d));
}

void	check_map(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;
	int x;
	int y;
	

	i = 0;
	x = 0;
	y = 0;
	
}

int		check_struct(t_check_struct *ret)
{
	if (ret->width == 1 && ret->height == 1 && ret->no == 1 &&
	 ret->so == 1 && ret->we == 1 && ret->ea == 1 && ret->s == 1 
	 && ret->f == 1 && ret->c == 1)
		return (1);
	return (0);
		
}

void	parse_line(char *line, t_cub3d *ptr)
{
	t_check_struct ret;
	char **tab;
	int i;
	
	i = 0;
	init_check_struct(&ret);
	tab = ft_split((const char*)line, ' ');
	separate_r(tab, ptr, &ret);
	separate_texture(tab, ptr, &ret);
	separate_color_f(tab, ptr, &ret);
	separate_color_c(tab,ptr, &ret);
	if (line[i] == 1 && check_struct(&ret) == 1)
	{
		check_map(tab, ptr, &ret);
	}
	/*free (*tab);
	*tab = NULL;*/
	i = -1;
	ft_printf("\n---------\n");
	while (tab[++i])
		ft_printf("%d ->%s<- ", i, tab[i]);

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
	while (get_next_line(fd, &line) == 1)
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