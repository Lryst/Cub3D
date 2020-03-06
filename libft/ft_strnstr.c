/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:29:43 by lryst             #+#    #+#             */
/*   Updated: 2019/11/08 12:18:40 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned long int	i;
	unsigned long int	n;
	char				*haystack;
	char				*needle;

	i = 0;
	haystack = (char*)s1;
	needle = (char*)s2;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i] && i < len)
	{
		n = 0;
		while (haystack[i + n] == needle[n] && i + n < len)
		{
			if (needle[n + 1] == 0)
				return (haystack + i);
			n++;
		}
		i++;
	}
	return (NULL);
}
