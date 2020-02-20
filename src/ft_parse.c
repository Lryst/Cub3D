/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/02/20 18:55:56 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_check_struct(t_check_struct *ret)
{
	ret->width = -1;
	ret->height = -1;
	ret->no = -1;
	ret->so = -1;
	ret->we = -1;
	ret->ea = -1;
	ret->s = -1;
	ret->f = -1;
	ret->c = -1;	
}

void	init_cub3d(t_cub3d *ptr)
{
	ft_bzero(ptr, sizeof(t_cub3d));
}

int		check_struct(t_check_struct *ret)
{
	if (ret->width == 1 && ret->height == 1 && ret->no == 1 &&
	 ret->so == 1 && ret->we == 1 && ret->ea == 1 && ret->s == 1 
	 && ret->f == 1 && ret->c == 1)
	 {
		// write(1, "OK\n", 3);
		return (1);
	 }
	return (0);
		
}
void	parse_line(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	char *tmp;
	int i;

	i = -1;
	i++;
	if (tab[i] == NULL)
		return;
	if (tab[i] != NULL)
	{
		tmp = ft_strtrim(tab[i], "\t \n \v \f \r");
		//printf("\n\n   TAB[I]     ->   {%s}\n\n", tab[i]);
		if (ft_strcmp("R", (const char *)tab[i]) == 0)
			separate_r(tab, ptr, ret);
		if (ft_strcmp("NO", (const char *)tab[i]) == 0)
			separate_texture_no(tab, ptr, ret);
		if (ft_strcmp("SO", (const char *)tab[i]) == 0)
			separate_texture_so(tab, ptr, ret);
		if (ft_strcmp("WE", (const char *)tab[i]) == 0)
			separate_texture_we(tab, ptr, ret);
		if (ft_strcmp("EA", (const char *)tab[i]) == 0)
			separate_texture_ea(tab, ptr, ret);
		if (ft_strcmp("F", (const char *)tab[i]) == 0)
			separate_color_f(tab, ptr, ret);
		if (ft_strcmp("C", (const char *)tab[i]) == 0)
			separate_color_c(tab, ptr, ret);
		return;
	}
	
}

void	parsing(int fd)
{
	t_cub3d ptr;
	t_check_struct ret;
	char *line;
	char**tab;
	int i;
	
	init_cub3d(&ptr);
	init_check_struct(&ret);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_split(line, ' ');
		parse_line(tab, &ptr, &ret);
	}
}

/*int i;
	i = -1;
	ft_printf("\n---------\n");
	while (tab[++i])
		ft_printf("->%s<- ", tab[i]);
		
		
		
		|| check_struct(&ret) == 0*/