/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:05:33 by lryst             #+#    #+#             */
/*   Updated: 2020/02/27 16:25:35 by lryst            ###   ########.fr       */
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
    ret->map = -1;
	ret->position = 0;
}

void	init_cub3d(t_cub3d *cub)
{
	ft_bzero(cub, sizeof(t_cub3d));
	cub->tmp = ft_newstring(0);
}

int		check_struct(t_check_struct *ret)
{
	if (ret->width == 1 && ret->height == 1 && ret->no == 1 &&
	 ret->so == 1 && ret->we == 1 && ret->ea == 1 && ret->s == 1 
	 && ret->f == 1 && ret->c == 1)
	 {
		return (1);
	 }
	return (0);
		
}
