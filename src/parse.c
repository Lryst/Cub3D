/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 20:47:14 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_line_2(t_cub3d *cub, t_check_struct *ret, int i)
{
	if (ft_strcmp("R", (const char *)cub->tab[i]) == 0)
		separate_r(cub->tab, cub, ret);
	if (ft_strcmp("NO", (const char *)cub->tab[i]) == 0)
		separate_texture_no(cub->tab, cub, ret);
	if (ft_strcmp("SO", (const char *)cub->tab[i]) == 0)
		separate_texture_so(cub->tab, cub, ret);
	if (ft_strcmp("WE", (const char *)cub->tab[i]) == 0)
		separate_texture_we(cub->tab, cub, ret);
	if (ft_strcmp("EA", (const char *)cub->tab[i]) == 0)
		separate_texture_ea(cub->tab, cub, ret);
	if (ft_strcmp("S", (const char *)cub->tab[i]) == 0)
		separate_texture_s(cub->tab, cub, ret);
	if (ft_strcmp("F", (const char *)cub->tab[i]) == 0)
		separate_color_f(cub->tab, cub, ret);
	if (ft_strcmp("C", (const char *)cub->tab[i]) == 0)
		separate_color_c(cub->tab, cub, ret);
}

void	parse_line(t_cub3d *cub, t_check_struct *ret)
{
	int i;

	i = -1;
	i++;
	if (cub->tab[i] == NULL)
		return;
	if (cub->tab[i] != NULL)
	{
		parse_line_2(cub, ret, i);
		return;
	}
}

void	parse_3(t_cub3d *cub, t_check_struct *ret)
{
	if (ft_strsame(cub->line, FLINE) == 1 && ret->map == 1)
	{
		write(1, "ERROR 3 MAP\n", 11);
		return;
	}
	if (ft_strsame(cub->line, SET) == 1)
	{
		cub->tmp = ft_strjoinfree_separate(cub->tmp, cub->line, '*');
		if (ft_strsame(cub->line, POSITION) == 1)
		{
			printf("bad possition, last line\n");
			return;
		}
		cub->count++;
		ret->map = 1;
	}
	if (ft_strsame(cub->line, SET) == 0 && ret->map == 1)
	{
		write(1, "ERROR 4 MAP\n", 10);
		return;
	}
}

void	parse_2(t_cub3d *cub, t_check_struct *ret)
{
	if (ft_strsame(cub->line, FLINE) == 1 && ret->map == 1)
	{
		write(1, "ERROR 1 MAP\n", 11);
		exit(EXIT_FAILURE);
	}
	if (ft_strsame(cub->line, SET) == 1 && check_struct(ret) == 1)
	{
		cub->tmp = ft_strjoinfree_separate(cub->tmp, cub->line, '*');
		ret->count = cub->count;
		check_position(ret, cub);
		cub->count++;
		ret->map = 1;
	}
	if (ft_strsame(cub->line, SET) == 0 && ret->map == 1 && check_struct(ret) == 1)
	{
		write(1, "ERROR 2 MAP\n", 10);
		return;
	}
	if (check_struct(ret) == 0)
	{
		cub->tab = ft_split_set(cub->line, ISSPACE);
		parse_line(cub, ret);
	}
	cub->line = NULL;
}

void	start_parsing(int fd, t_cub3d *cub)
{
	t_check_struct ret;
	int i;
	
	i = 0;
	init_cub3d(cub);
	init_check_struct(&ret);
	cub->tmp = ft_newstring(0);
	while (get_next_line(fd, &cub->line) == 1)
		parse_2(cub, &ret);
	parse_3(cub, &ret);
	cub->posX = ret.posX;
	cub->posY = ret.posY;
	cub->map_height = cub->count - 1;
	cub->map_width = ft_strlen(cub->line);
	if (cub->tmp != NULL && check_struct(&ret) == 1 && ret.position == 1)
		check_map(cub->tmp, cub, cub->count);
	if (ret.position != 1)
	{
		ft_printf("ERROR!!! bad position : [%d]\n", ret.position);
		exit(EXIT_FAILURE);
	}
	return;
}
