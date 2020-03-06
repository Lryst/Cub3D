/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:36:46 by lryst             #+#    #+#             */
/*   Updated: 2019/11/07 13:29:12 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				u;
	unsigned char		*dst;
	unsigned char		*sr;

	u = 0;
	dst = (unsigned char*)dest;
	sr = (unsigned char*)src;
	if (n == 0)
		return (NULL);
	while (u < n)
	{
		dst[u] = sr[u];
		if (sr[u] == (unsigned char)c || dst[u] == (unsigned char)c)
			return (dst + (++u));
		u++;
	}
	return (NULL);
}
