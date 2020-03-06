/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:39:59 by lryst             #+#    #+#             */
/*   Updated: 2019/11/04 13:31:55 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memlen(void *s)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
