/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:54:14 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:09:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_position_sprite(t_cub3d *cub)
{
	int a;
	int x;
	int y;

	a = 0;
	x = 0;
	y = 0;
	if (!(cub->map.sprite.pos_sprite = (int**)malloc(sizeof(int*) *
	cub->map.sprite.nbr + 1)))
		ft_error("malloc failed");
	while (x++ < cub->map_height)
	{
		y = 0;
		while (y++ < cub->map_width - 1)
		{
			if (cub->map.line[x][y] == '2')
			{
				cub->map.sprite.pos_sprite[a] = (int*)malloc(sizeof(int) * 2);
				cub->map.sprite.pos_sprite[a][0] = x;
				cub->map.sprite.pos_sprite[a][1] = y;
				a++;
			}
		}
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
				cub->map.sprite.nbr += 1;
			y++;
		}
		x++;
	}
	get_position_sprite(cub);
}
