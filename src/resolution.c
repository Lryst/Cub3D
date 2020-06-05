/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:12:03 by lryst             #+#    #+#             */
/*   Updated: 2020/02/26 20:03:21 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <string.h>

void	separate_r(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;

	i = 0;
	if (ret->width == 1 || ret->height == 1)
		ft_error("there is not only one resolution");
	if (ret->width == -1 || ret->height == -1)
	{
		if (ft_strcmp("R", (const char*)tab[i]) == 0)
		{
			if (tab[i + 1] != NULL && tab[i + 2] != NULL && tab[i + 3] == NULL)
			{
				if (tab[i + 1] >= 0 && tab[i + 2] >= 0 && tab[i + 3] == NULL)
				{
					if (ft_atoi(tab[i + 1]) <= 0 || ft_atoi(tab[i + 2]) <= 0 )
						ft_error("bad resolution");
					cub->width = ft_atoi(tab[i + 1]);
					cub->height = ft_atoi(tab[i + 2]);
					ret->width = 1;
					ret->height = 1;
					ft_printf("Width %d\n",cub->width);
					ft_printf("Height %d\n", cub->height);
				}
			}
		}
	}
	else
		ft_error("EURREURE RESOLUTION DOMMAGE...\n");
}