/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:07:11 by lryst             #+#    #+#             */
/*   Updated: 2019/11/04 13:56:53 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*tab;
	long int	i;
	long int	u;

	i = 0;
	u = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tab = (char*)malloc(sizeof(char) * (ft_strlen((char *)s1) +
				ft_strlen((char *)s2)) + 1);
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[u])
	{
		tab[i] = s2[u];
		i++;
		u++;
	}
	tab[i] = '\0';
	return (tab);
}
