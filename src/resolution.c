/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:12:03 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 22:12:15 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"
#include <string.h>

int		check_line_is_num(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 47 || str[i] > 58)
			return (0);
		i++;
	}
	return (1);
}

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
				if (check_line_is_num(tab[i + 1]) == 1 && check_line_is_num(tab[i + 2]) == 1
				&& ft_atoi(tab[i + 1]) >= 0 && ft_atoi(tab[i + 2]) >= 0 )
				{
					cub->width = ft_atoi(tab[i + 1]);
					cub->height = ft_atoi(tab[i + 2]);
					ret->width = 1;
					ret->height = 1;
				}
				else
					ft_error("bad resolution");
			}
			else
				ft_error("bad resolution");
		}
	}
}

