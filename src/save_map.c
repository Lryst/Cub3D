/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:38:37 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 20:48:40 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_position_sprite(t_cub3d*cub)
{
	int a;
	int x;
	int y;

	a = 0;
	x = 0;
	y = 0;
	if (!(cub->map.sprite.pos_sprite = (int**)malloc(sizeof(int*) * cub->map.sprite.sprite_nbr + 1)))
	{
		return;
	}
	while (x < cub->map_height)
	{
		y = 0;
		while (y < cub->map_width - 1)
		{
			if (cub->map.line[x][y] == '2')
			{
				cub->map.sprite.pos_sprite[a] = (int*)malloc(sizeof(int) * 2);
				cub->map.sprite.pos_sprite[a][0] = x;
				cub->map.sprite.pos_sprite[a][1] = y;
				a++;
			}
			y++;
		}
		x++;
	}

}

void	check_nbr_of_sprite(t_cub3d *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < cub->map_height)
	{
		y = 0;
		while (y < cub->map_width)
		{
			if (cub->map.line[x][y] == '2')
				cub->map.sprite.sprite_nbr += 1;
			y++;
		}
		x++;
	}
	get_position_sprite(cub);
}

int		check_map_space(char **map, int j, int i)
{
	if (map[j - 1][i - 1] == '1' && map[j - 1][i] == '1' 
		&& map[j - 1][i + 1] == '1' && map[j][i + 1] == '1'
		&& map[j][i - 1] == '1' && map[j + 1][i - 1] == '1'
		&& map[j + 1][i] == '1' && map[j + 1][i + 1] == '1')
		return (1);
	return (0);
}

int 	parcour_closed_map(char **map, int j, int i, int height)
{
	if (map[j][i] == '1'|| map[j][i] == '.')
		return (1);
	if (map[j][i] != '1' && (i <= 0 || i >= (int)ft_strlen(map[j]) || j <= 0 || j >= height))
		return (0);
	if (map[j][i] == ' ')
	{
		if (check_map_space(map, j, i) == 1)
			return (1);
		return (0);
	}
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

int		check_closed_map(t_cub3d *cub)
{
	int i;
	int ret;
	
	cub->map.sprite.sprite_nbr = 0;
	cub->closed_map = NULL;
	cub->closed_map = malloc(sizeof(char*) * cub->map.height + 30);
	cub->closed_map[cub->map.height] = NULL;
	i = -1;
	while (++i < cub->map.height)
	{
		cub->closed_map[i] = NULL;
		cub->closed_map[i] = ft_strdup(cub->map.line[i]);
	}
	ret = parcour_closed_map(cub->closed_map, cub->posX, cub->posY, cub->map_height);
	i = -1;
	check_nbr_of_sprite(cub);
	//ft_printf("\n");
	//ft_printf("nombre sprite [%d]\n", c->map.sprite.sprite_nbr);
	while (++i <= cub->map_height)
		ft_printf("map: %s\n", cub->closed_map[i]);
	//free_double_tab(cub->map.line);
	return (ret);
}

void	check_map(char *str, t_cub3d *cub, int count)
{
	char **tab;
	int i;

	i = -1;
	tab = ft_split((const char*)str, '*');
	free(str);
	cub->map.line = NULL;
	cub->map.height = count;
	if (!(cub->map.line = (char**)malloc(sizeof(cub->map.line) * (count + 1))))
		ft_error("malloc abort");
	while (tab[++i])
	{
		cub->map.line[i] = NULL;
		if (!(cub->map.line[i] = ft_strdup(tab[i])))
			ft_error("ft_strdup failed");
	}
	free_double_tab(tab);
	if (!check_closed_map(cub))
		ft_error("not closed map");
}
