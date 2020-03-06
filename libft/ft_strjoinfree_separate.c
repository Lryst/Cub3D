/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree_separate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:29:40 by lryst             #+#    #+#             */
/*   Updated: 2020/02/25 20:21:06 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree_separate(char *s1, char *s2, char c)
{
	char	*tab;
	int		i;
    int     a;
	int		u;

	i = 0;
	u = 0;
    a = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(tab = (char*)malloc(sizeof(char) * (ft_strlen((char *)s1) +
				ft_strlen((char *)s2) + 2))))
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[a];
		a++;
		i++;
	}
	tab[i] = c;
	i++;
	while (s2[u])
    {
		tab[i++] = s2[u++];
    }
	tab[i] = '\0';
	free(s1);
	s1 = NULL;
	return (tab);
}
