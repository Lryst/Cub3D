/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:59:39 by lryst             #+#    #+#             */
/*   Updated: 2019/12/17 11:18:23 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(long value, char *base)
{
	char	*ret;
	int		number_size;
	int		i;
    int     base_size;

    base_size = ft_strlen(base);
    value < 0 ? value = 4294967295 - value : 0;
	number_size = digit_count(value, base_size);
	ret = (char *)malloc(sizeof(char) * (number_size + 1));
	i = 1;
	while (value != 0)
	{
		ret[number_size - i++] = base[value % base_size];
		value /= base_size;
	}
	ret[number_size] = '\0';
	return (ret);
}
