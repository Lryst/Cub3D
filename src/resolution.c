/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:12:03 by lryst             #+#    #+#             */
/*   Updated: 2020/02/18 17:56:38 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	separate_r(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;

	i = 0;
	if (ft_strcmp("R", (const char*)tab[i]) == 0)
	{
		if (tab[i + 1] != NULL && tab[i + 2] != NULL && tab[i + 3] == NULL)
		{
			if (tab[i + 1] > 0 && tab[i + 2] > 0 && tab[i + 3] == NULL)
			{
				ptr->width = ft_atoi(tab[i + 1]);
				ptr->height = ft_atoi(tab[i + 2]);
				ret->width = 1;
				ret->height = 1;
			}
		}
		//ft_printf("W %d\n", ptr->width);
		//ft_printf("H %d\n", ptr->height);
	}
}