/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:38:37 by lryst             #+#    #+#             */
/*   Updated: 2020/02/25 21:50:57 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		len = 0;
		len = ft_strlen(tab[i]);
		if (!(ptr->map.line[j] = (char*)malloc(sizeof(char) * (len + 1))))
			return;
		ptr->map.line[j] = ft_strdup(tab[i]);
		ft_printf("line %s\n", ptr->map.line[j]);
		i++;
		j++;
	}
}
