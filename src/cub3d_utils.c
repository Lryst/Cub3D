/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:06:16 by lryst             #+#    #+#             */
/*   Updated: 2020/06/13 23:16:29 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	check_bad_line(char **tab, int i)
{
	if (ft_strcmp("R", (const char *)tab[i]) != 0 &&
	ft_strcmp("NO", (const char *)tab[i]) != 0 &&
	ft_strcmp("SO", (const char *)tab[i]) != 0 &&
	ft_strcmp("WE", (const char *)tab[i]) != 0 &&
	ft_strcmp("EA", (const char *)tab[i]) != 0 &&
	ft_strcmp("S", (const char *)tab[i]) != 0 &&
	ft_strcmp("F", (const char *)tab[i]) != 0 &&
	ft_strcmp("C", (const char *)tab[i]) != 0)
		ft_error("bad charactere in .cub");
}

int		ft_strsame(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !s1[0] || !s2[0])
		return (0);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			i++;
			j = 0;
		}
		if (s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
		{
			return (0);
		}
	}
	return (1);
}

int		check_position(t_check_struct *ret, t_cub3d *cub)
{
	int i;

	i = 0;
	if (!cub->line)
		return (0);
	while (cub->line[i])
	{
		if (ft_strspn(POSITION, cub->line[i]) == 1)
		{
			++ret->position;
			ret->posY = i;
			cub->orientation = cub->line[i];
			ret->posX = ret->count;
		}
		i++;
	}
	return (1);
}
