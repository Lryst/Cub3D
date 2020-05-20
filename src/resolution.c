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

void	separate_r(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;

	i = 0;
	if (ret->width == 1 || ret->height == 1)
	{
		ft_printf("IL Y A DEJA UNE resolution POTO\n");
		return;
	}
	if (ret->width == -1 || ret->height == -1)
	{
		if (ft_strcmp("R", (const char*)tab[i]) == 0)
		{
			if (tab[i + 1] != NULL && tab[i + 2] != NULL && tab[i + 3] == NULL)
			{
				if (tab[i + 1] >= 0 && tab[i + 2] >= 0 && tab[i + 3] == NULL)
				{
					ptr->width = ft_atoi(tab[i + 1]);
					ptr->height = ft_atoi(tab[i + 2]);
					ret->width = 1;
					ret->height = 1;
					//ft_printf("Width %d\n",ptr->width);
					//ft_printf("Height %d\n", ptr->height);
				}
			}
		}
	}
	else
	{
		ft_printf("EURREURE RESOLUTION DOMMAGE...\n");
		return;
	}
}