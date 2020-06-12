/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:11:05 by lryst             #+#    #+#             */
/*   Updated: 2020/02/21 14:33:44 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	separate_texture_no(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;

	i = 0;
	if (ret->no == -1)
	{
		if (ft_strcmp("NO", (const char *)tab[i]) == 0)
		{
			if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			{
				cub->no.path = ft_strdup(tab[i + 1]);
				ret->no = 1;
			}
			else
				ft_error("bad line in fd");
		}
	}
	else
		ft_error("multi north texture");
}

void	separate_texture_so(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;

	i = 0;
	if (ret->so == -1)
	{
		if (ft_strcmp("SO", (const char *)tab[i]) == 0)
		{
			if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			{
				cub->so.path = ft_strdup(tab[i + 1]);
				ret->so = 1;
			}
			else
				ft_error("bad line in fd");
		}
	}
	else
		ft_error("multi south texture");
}

void	separate_texture_we(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;
	
	i = 0;
	if (ret->we == -1)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			if (ft_strcmp("WE", (const char *)tab[i]) == 0)
			{
				cub->we.path = ft_strdup(tab[i + 1]);
				ret->we = 1;
			}
			else
				ft_error("bad line in fd");
		}
	}
	else
		ft_error("multi west texture");
}

void	separate_texture_ea(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;
	
	i = 0;
	if (ret->ea == -1)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			if (ft_strcmp("EA", (const char *)tab[i]) == 0)
			{
				cub->ea.path = ft_strdup(tab[i + 1]);
				ret->ea = 1;
			}
					else
				ft_error("bad line in fd");
		}
	}
	else
		ft_error("multi east texture");
}

void	separate_texture_s(char **tab, t_cub3d *cub, t_check_struct *ret)
{
	int i;
	
	i = 0;
	if (ret->s == -1)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			if (ft_strcmp("S", (const char *)tab[i]) == 0)
			{
				cub->s.path = ft_strdup(tab[i + 1]);
				ret->s = 1;
			}
			else
				ft_error("bad line in fd");
		}
	}
	else
		ft_error("multi sprite texture");
}
