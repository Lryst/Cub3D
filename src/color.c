/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:09:41 by lryst             #+#    #+#             */
/*   Updated: 2020/02/18 17:55:36 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	separate_color_f(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;
	int a;
	char **color = NULL;

	i = 0;
	a = 0;
	if (ft_strcmp("F", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			color = ft_split(tab[i + 1],',');
			if (ft_atoi(color[a]) > -1 && ft_atoi(color[a]) < 256)
			{
				if (ft_atoi(color[a + 1]) > -1 && ft_atoi(color[a + 1]) < 256)
				{
					if (ft_atoi(color[a + 1]) > -1 && ft_atoi(color[a + 1]) < 256)
					{
						ptr->f.red = ft_atoi(color[a]);
						ptr->f.green = ft_atoi(color[a + 1]);
						ptr->f.blue = ft_atoi(color[a + 2]);
						ret->f = 1;
					}
				}
			}
		}
		free(*color);
		*color = NULL;
		//ft_printf("F.red %d\n", ptr->f.red);
		//ft_printf("F.green %d\n", ptr->f.green);
		//ft_printf("F.blue %d\n", ptr->f.blue);
	}
	//ft_printf("F %s\n", ptr->f);
}

void	separate_color_c(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;
	int a;
	char **color = NULL;

	i = 0;
	a = 0;
	if (ft_strcmp("C", (const char *)tab[i]) == 0)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			color = ft_split(tab[i + 1],',');
			if (ft_atoi(color[a]) > -1 && ft_atoi(color[a]) < 256)
			{
				if (ft_atoi(color[a + 1]) > -1 && ft_atoi(color[a + 1]) < 256)
				{
					if (ft_atoi(color[a + 1]) > -1 && ft_atoi(color[a + 1]) < 256)
					{
						ptr->c.red = ft_atoi(color[a]);
						ptr->c.green = ft_atoi(color[a + 1]);
						ptr->c.blue = ft_atoi(color[a + 2]);
						ret->c = 0;
					}
				}
			}
		}
		free(*color);
		*color = NULL;
		//ft_printf("C.red %d\n", ptr->c.red);
		//ft_printf("C.green %d\n", ptr->c.green);
		//ft_printf("C.blue %d\n", ptr->c.blue);
	}
	//ft_printf("F %s\n", ptr->f);
}