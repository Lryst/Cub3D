/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:09:41 by lryst             #+#    #+#             */
/*   Updated: 2020/02/26 20:03:53 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_is_tab_num(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] < 47 || tab[i][j] > 58)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	put_color_in_struct(int *tex_color, char **color)
{
	*tex_color = 0;
	*tex_color += ft_atoi(color[0]) << 16;
	*tex_color += ft_atoi(color[1]) << 8;
	*tex_color += ft_atoi(color[2]);
}

void	separate_color_f(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;
	char **color = NULL;

	i = 0;
	if (ret->f != -1)
		ft_error("multi color F");
	if (ret->f == -1)
	{
		if (ft_strcmp("F", (const char *)tab[i]) == 0)
		{
			if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			{
				color = ft_split(tab[i + 1],',');
				if (check_is_tab_num(color) == 1 
					&& ft_atoi(color[0]) > -1 && ft_atoi(color[0]) < 256 
					&& ft_atoi(color[1]) > -1 && ft_atoi(color[1]) < 256 
					&& ft_atoi(color[2]) > -1 && ft_atoi(color[2]) < 256)
				{
					put_color_in_struct(&cub->f.color, color);
					ret->f = 1;
				}
				free_double_tab(color);
			}
			else
				ft_error("bad color f");
		}
	}	
}

void	separate_color_c(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;
	char **color = NULL;

	i = 0;
	if (ret->c == 1)
		ft_error("multi color C");
	if (ret->c == -1)
	{
		if (ft_strcmp("C", (const char *)tab[i]) == 0)
		{
			if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			{
				color = ft_split(tab[i + 1],',');
				if (check_is_tab_num(color) == 1 
					&& ft_atoi(color[0]) > -1 && ft_atoi(color[0]) < 256 
					&& ft_atoi(color[1]) > -1 && ft_atoi(color[1]) < 256 
					&& ft_atoi(color[2]) > -1 && ft_atoi(color[2]) < 256)
				{
					put_color_in_struct(&cub->c.color, color);
					ret->c = 1;
				}
				free_double_tab(color);
			}
			else
				ft_error("bad color c");
		}
	}
}
