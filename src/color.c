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

void	separate_color_f(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;
	int a;
	char **color = NULL;

	i = 0;
	a = 0;
	if (ret->f == -1)
	{
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
							cub->f.red = ft_atoi(color[a]);
							cub->f.green = ft_atoi(color[a + 1]);
							cub->f.blue = ft_atoi(color[a + 2]);
							cub->f.color = 0;
							cub->f.color += cub->f.red << 16;
							cub->f.color += cub->f.green << 8;
							cub->f.color += cub->f.blue;
							ret->f = 1;
						}
					}
				}
				free_double_tab(color);
			}
			//ft_printf("F.red %d\n", ptr->f.red);
			//ft_printf("F.green %d\n", ptr->f.green);
			//ft_printf("F.blue %d\n", ptr->f.blue);
		}
	}
	else
	{
		//ft_printf("EURREURE color f DOMMAGE...\n");
		return;
	}
	//ft_printf("F %s\n", ptr->f);
}

void	separate_color_c(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;
	int a;
	char **color = NULL;

	i = 0;
	a = 0;
	if (ret->c == -1)
	{
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
							cub->c.red = ft_atoi(color[a]);
							cub->c.green = ft_atoi(color[a + 1]);
							cub->c.blue = ft_atoi(color[a + 2]);
							cub->c.color = 0;
							cub->c.color += cub->c.red << 16;
							cub->c.color += cub->c.green << 8;
							cub->c.color += cub->c.blue;
							ret->c = 1;
						}
					}
				}
				free_double_tab(color);
			}
			//ft_printf("C.red %d\n", cub->c.red);
			//ft_printf("C.green %d\n", cub->c.green);
			//ft_printf("C.blue %d\n", cub->c.blue);
		}
	}
	else
	{
		//ft_printf("EURREURE color c DOMMAGE...\n");
		return;
	}
	//ft_printf("F %s\n", cub->f);
}