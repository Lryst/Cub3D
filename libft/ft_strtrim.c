/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:07:53 by lryst             #+#    #+#             */
/*   Updated: 2020/02/21 14:04:34 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		n;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strspn((char*)set, s1[i]))
		i++;
	n = ft_strlen(s1) - 1;
	while (n >= 0 && ft_strspn((char*)set, s1[n]))
		n--;
	n++;
	str = (char*)malloc(sizeof(char) * (n ? n - i + 1 : 1));
	if (!str)
		return (NULL);
	if (s1[i] == '\0')
	{
		str[0] = '\0';
		return (str);
	}
	str = n ? ft_substr(s1, (unsigned int)i, (unsigned int)n - i) : 0;
	return (str);
}
