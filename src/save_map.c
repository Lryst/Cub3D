/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:38:37 by lryst             #+#    #+#             */
/*   Updated: 2020/02/27 18:32:57 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int 	parcour_closed_map(char **map, int j, int i, int height)
{
	if (map[j][i] == '1' || map[j][i] == '.')
		return (1);
	if (map[j][i] != '1' && (i <= 0 || i >= (int)ft_strlen(map[j]) || j <= 0 || j >= height))
		return (0);
	map[j][i] = '.';
	return (parcour_closed_map(map, j - 1, i - 1, height)
	&& parcour_closed_map(map, j - 1, i, height)
	&& parcour_closed_map(map, j - 1, i + 1, height)
	&& parcour_closed_map(map, j, i + 1, height)
	&& parcour_closed_map(map, j, i - 1, height)
	&& parcour_closed_map(map, j + 1, i - 1, height)
	&& parcour_closed_map(map, j + 1, i, height)
	&& parcour_closed_map(map, j + 1, i + 1, height)
	);
}

int		check_closed_map(t_cub3d *c)
{
	int i;
	
	c->closed_map = malloc(sizeof(char*) * c->map.height + 1);
	c->closed_map[c->map.height] = NULL;
	i = -1;
	while (++i < c->map.height)
		c->closed_map[i] = ft_strdup(c->map.line[i]);
	int ret = parcour_closed_map(c->closed_map, c->posy, c->posx, c->map_height);
	i = -1;
	ft_printf("\n");
	while (++i <= c->map_height)
		ft_printf("map: %s\n", c->closed_map[i]);
	return (ret);
}

void	check_map(char *str, t_cub3d *ptr, int count)
{
	char **tab;
	int i;
	int j;
	int k;
	int l;
	int len;

	i = 0;
	len = 0;
	j = 0;
	k = -1;
	l = 0;
	tab = ft_split((const char*)str, '*');
	ft_strlen(str);
	ptr->map.height = count;
	if (!(ptr->map.line = (char**)malloc(sizeof(ptr->map.line) * (count + 1))))
		return;
	while (tab[i])
	{
		len = ft_strlen(tab[i]);
		if (!(ptr->map.line[j] = (char*)malloc(sizeof(char) * (len + 1))))
			return;
		ptr->map.line[j] = ft_strdup(tab[i]);
		ft_printf("line %s\n", ptr->map.line[j]);
		i++;
		j++;
	}
	if (!check_closed_map(ptr))
		ft_printf("AAAAAAAAAHHH!!!!nana NANA\nnot closed map\n");
}
