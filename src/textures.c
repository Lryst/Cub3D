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

void	separate_texture_no(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;

	i = 0;
	if (ret->no == -1)
	{
		if (ft_strcmp("NO", (const char *)tab[i]) == 0)
		{
			if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			{
				ptr->no.path = ft_strdup(tab[i + 1]);
				ret->no = 1;
			}
			//ft_printf("NO %s\n", ptr->no.path);
		}
	}
	else
	{
		//ft_printf("ERREURE TEXTURE no, DESO BRO ...\n");
		return;
	}
}

void	separate_texture_so(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;

	i = 0;
	if (ret->so == -1)
	{
		if (ft_strcmp("SO", (const char *)tab[i]) == 0)
		{
			if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
			{
				ptr->so.path = ft_strdup(tab[i + 1]);
				ret->so = 1;
			}
			//ft_printf("SO %s\n", ptr->so.path);
		}
	}
	else
	{
		//ft_printf("ERREURE TEXTURE so, DESO BRO ...\n");
		return;
	}
}

void	separate_texture_we(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;
	
	i = 0;
	if (ret->we == -1)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			if (ft_strcmp("WE", (const char *)tab[i]) == 0)
			{
				ptr->we.path = ft_strdup(tab[i + 1]);
				ret->we = 1;
			}
			//ft_printf("WE %s\n", ptr->we.path);
		}
	}
	else
	{
		//ft_printf("ERREURE TEXTURE we, DESO BRO ...\n");
		return;
	}
}

void	separate_texture_ea(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;
	
	i = 0;
	if (ret->ea == -1)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			if (ft_strcmp("EA", (const char *)tab[i]) == 0)
			{
				ptr->ea.path = ft_strdup(tab[i + 1]);
				ret->ea = 1;
			}
			//ft_printf("EA %s\n", ptr->ea.path);
		}
	}
	else
	{
		//ft_printf("ERREURE TEXTURE ea, DESO BRO ...\n");
		return;
	}
}

void	separate_texture_s(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;
	
	i = 0;
	if (ret->s == -1)
	{
		if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 2] == NULL)
		{
			if (ft_strcmp("S", (const char *)tab[i]) == 0)
			{
				ptr->s.path = ft_strdup(tab[i + 1]);
				ret->s = 1;
			}
			//ft_printf("S %s\n", ptr->s.path);
		}
	}
	else
	{
		//ft_printf("ERREURE TEXTURE s, DESO BRO ...\n");
		return;
	}
}
