/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/02/21 11:36:25 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		if (ft_strcmp("S", (const char *)tab[i]) == 0)
			separate_texture_s(tab, ptr, ret);
		if (ft_strcmp("F", (const char *)tab[i]) == 0)
			separate_color_f(tab, ptr, ret);
		if (ft_strcmp("C", (const char *)tab[i]) == 0)
			separate_color_c(tab, ptr, ret);
		return;
	}
	
}

/*void	parse_map(char **tab, t_cub3d *ptr)
{
	
}*/

void	parsing(int fd)
{
	t_cub3d ptr;
	t_check_struct ret;
	char *line;
	char**tab;
	int i;
	int count;
	int start;
	
	count = 0;
	start = 0;
	i = 0;
	init_cub3d(&ptr);
	init_check_struct(&ret);
	while (get_next_line(fd, &line) == 1)
	{
		count++;
		free(line);
		line = NULL;
	}
	ft_printf("NBR DE LINE : %d\n", count);
	//ft_printf("line -> %s\n", line);
	while (get_next_line(fd, &line) == 1 && start < count && check_struct(&ret) == 0)
	{
		write(1, "ok\n", 3);
		tab = ft_split(line, ' ');
		write(1, "ok\n", 3);
		parse_line(tab, &ptr, &ret);
		start++;
	}
	ft_printf("NBR DE LINE INFO : %d\n", start);
	
}

/*int i;
	i = -1;
	ft_printf("\n---------\n");
	while (tab[++i])
		ft_printf("->%s<- ", tab[i]);
		
		
		
		|| check_struct(&ret) == 0*/