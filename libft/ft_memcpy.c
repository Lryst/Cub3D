/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:36:38 by lryst             #+#    #+#             */
/*   Updated: 2019/11/07 13:27:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	unsigned int	u;

	u = 0;
	dst = (unsigned char*)dest;
	sr = (unsigned char*)src;
	if (!n || sr == dst)
		return (dst);
	while (n--)
	{
		dst[u] = sr[u];
		u++;
	}
	return (dst);
}
