/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:11:35 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 00:23:34 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char ***str)
{
	free(**str);
	**str = NULL;
}

int		ft_strspm(char *set, char u)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == u)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_intline(char **line, char **tmp)
{
	char	*str;
	int		i;

	i = ft_strspm(*tmp, '\n');
	if (i != -1)
	{
		*line = ft_newstring(i + 1);
		ft_memcpy(*line, *tmp, i);
		(*line)[i] = '\0';
		str = ft_strdup(*tmp + i + 1);
		ft_free(&tmp);
		*tmp = str;
		return (1);
	}
	*line = ft_strdup(*tmp);
	ft_free(&tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[GNL_BUF_SIZE + 1];
	int			ret;
	static char *tmp = NULL;

	if (fd < 0 || !line || GNL_BUF_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!tmp)
		tmp = ft_newstring(0);
	while (ft_strspm(tmp, '\n') == -1 && (ret = read(fd,
	buf, GNL_BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoinfree(tmp, buf)))
			return (-1);
	}
	return (ft_intline(line, &tmp));
}
