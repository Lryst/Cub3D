/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/02/21 16:24:45 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_line(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;

	i = -1;
	i++;
	if (tab[i] == NULL)
		return;
	if (tab[i] != NULL)
	{
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


int	ft_strsame(char *s1, char *s2)
{
	int i;
	int j;
	

	i = 0;
	write(1, "ok\n", 3);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j])
			i++;
		if (s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
			write(1, "0\n", 2);	
	}
	write(1, "1\n", 2);
	return (0);
}


/*void	save_map(char **tab, t_cub3d *ptr)
{
	int i;
	int k;
	static int index = 0;
	
	i = 0;
	k = 0;
	if (tab[i] && ft_strsame(set, tab[i]) == 1)
	{
		ptr->map[i] = ft_strdup(tab[i]);
		i++;
	}
	ft_printf("ptr->map :{%s}\n", ptr->map[index]);
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
	/*while (get_next_line(fd, &line) == 1)
	{
		while (line[i])
		{
			if (check_line == 1)
				count++;
			i++;
		}
		i = 0;
		free(line);
		line = NULL;
	}
	ft_printf("NBR DE LINE : %d\n", count);
	//ft_printf("line -> %s\n", line);*/
	while (get_next_line(fd, &line) == 1)
	{
		if (check_struct(&ret) == 0)
		{
			tab = ft_split_set(line, ISSPACE);
			parse_line(tab, &ptr, &ret);
			free(tab);
			tab = NULL;
		}
		if (check_struct(&ret) == 1 && ptr.map.error != 1)
		{
			
			if (ft_strsame(line, SET) == 1)
			{
				write(1, "ok\n", 3);
				ptr.map.line[i] = ft_strdup(line);
				ft_printf("MAP.LINE[I] -> {%s}\n", ptr.map.line[i]);
				i++;
			}
			else
				ptr.map.error = 1;			
		}
		free(line);
		line = NULL;
	}
	//free(&ptr);
	//ft_printf("NBR DE LINE INFO : %d\n", start);
	
}

/*int i;
	i = -1;
	ft_printf("\n---------\n");
	while (tab[++i])
		ft_printf("->%s<- ", tab[i]);
		
		
		
		|| check_struct(&ret) == 0*/