/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:35:44 by lryst             #+#    #+#             */
/*   Updated: 2020/02/13 16:36:01 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstring(size_t i)
{
	char	*str;
	size_t	zero;

	zero = 0;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (str && zero < i + 1)
	{
		str[zero] = '\0';
		zero++;
	}
	return (str);
}
