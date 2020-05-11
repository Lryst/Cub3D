/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:09:51 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 20:47:14 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_line(char **tab, t_cub3d *ptr, t_check_struct *ret)
{
	int i;

	i = -1;
	i++;
	if (tab[i] == NULL)
		return;
	if (tab[i] != NULL)
	{
		if (ft_strcmp("R", (const char *)tab[i]) == 0)
			separate_r(tab, ptr, ret);
		if (ft_strcmp("NO", (const char *)tab[i]) == 0)
			separate_texture_no(tab, ptr, ret);
		if (ft_strcmp("SO", (const char *)tab[i]) == 0)
			separate_texture_so(tab, ptr, ret);
		if (ft_strcmp("WE", (const char *)tab[i]) == 0)
			separate_texture_we(tab, ptr, ret);
		if (ft_strcmp("EA", (const char *)tab[i]) == 0)
			separate_texture_ea(tab, ptr, ret);
		if (ft_strcmp("S", (const char *)tab[i]) == 0)
			separate_texture_s(tab, ptr, ret);
		if (ft_strcmp("F", (const char *)tab[i]) == 0)
			separate_color_f(tab, ptr, ret);
		if (ft_strcmp("C", (const char *)tab[i]) == 0)
			separate_color_c(tab, ptr, ret);
		return;
	}
}

int	ft_strsame(char *s1, char *s2)
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

char	*ft_skip_space(char *str)
{
	char *tmp;
	int count;
	int i;
	int j;

	j = 0;
	i = 0;
	count = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (ft_strspn(ISSPACE, str[i]))
			count++;
		i++;
	}
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str) - count + 1)))
		return (NULL);
	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
		tmp[j++] = str[i++];
	while (str[i])
	{
		if (!ft_strspn(ISSPACE, str[i]))
			tmp[j++] = str[i++];
		else
			i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int		check_position(char *str, t_check_struct *ret, t_cub3d *cub)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strspn(POSITION, str[i]) == 1)
		{
			++ret->position;
			ret->posY = i;
			cub->orientation = str[i];
			printf("orientation = [%c]\n", str[i]);
			ret->posX = ret->count;
		}
		i++;
	}
	return(1);
}

void	parsing(int fd, t_cub3d *ptr)
{
	t_check_struct ret;
	char *line;
	char **tab;
	char *tmp;
	int i;
	int count;
	
	count = 0;
	i = 0;
	init_cub3d(ptr);
	init_check_struct(&ret);
	tmp = ft_newstring(0);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strsame(line, FLINE) == 1 && ret.map == 1)
		{
			write(1, "ERROR 1 MAP\n", 11);
			return;
		}
		if (ft_strsame(line, SET) == 1 && check_struct(&ret) == 1)
		{
			tmp = ft_strjoinfree_separate(tmp, line, '*');
			ret.count = count;
			check_position(line, &ret, ptr);
			count++;
			ret.map = 1;
		}
		if (ft_strsame(line, SET) == 0 && ret.map == 1 && check_struct(&ret) == 1)
		{
			write(1, "ERROR 2 MAP\n", 10);
			return;
		}
		if (check_struct(&ret) == 0)
		{
			tab = ft_split_set(line, ISSPACE);
			parse_line(tab, ptr, &ret);
			//ft_printf("line -> %s\n", line);
		}
		line = NULL;
	}
	if (ft_strsame(line, FLINE) == 1 && ret.map == 1)
	{
		write(1, "ERROR 3 MAP\n", 11);
		return;
	}
	
	//write(1, "ok\n", 3);
	if (ft_strsame(line, SET) == 1)
	{
		//---------------------------------------------------------------------
		//str = ft_skip_space(line);
		tmp = ft_strjoinfree_separate(tmp, line, '*');
		check_position(line, &ret, ptr);
		//free(str);
		//ft_printf("tmp : \n{%s}\n", tmp);
			count++;
		ret.map = 1;
	}
	if (ft_strsame(line, SET) == 0 && ret.map == 1)
	{
		write(1, "ERROR 4 MAP\n", 10);
		return;
	}
	ptr->posX = ret.posX;
	ptr->posY = ret.posY;
	ptr->map_height = count - 1;
	ptr->map_width = ft_strlen(line);
	if (tmp != NULL && check_struct(&ret) == 1 && ret.position == 1)
	{
		//ft_printf("TMP-> {%s}\n", tmp);
		check_map(tmp, ptr, count);
	}
	if (ret.position != 1)
	{
		ft_printf("ERROR!!! bad position : [%d]\n", ret.position);
		return;
	}
	return;
}

/*int i;
	i = -1;
	ft_printf("\n---------\n");
	while (tab[++i])
		ft_printf("->%s<- ", tab[i]);
		
		if (ft_strsame(line, FLINE) == 1)
			{
				write(1, "ERROR 1 MAP\n", 11);
				return;
			}
		
		|| check_struct(&ret) == 0*/