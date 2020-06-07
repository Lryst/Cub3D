/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:40:52 by lryst             #+#    #+#             */
/*   Updated: 2020/02/13 20:34:33 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_nbr(const char *str, int *i)
{
	int nbr;

	nbr = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = nbr * 10 + (str[*i] - 48);
		*i = *i + 1;
	}
	return (nbr);
}

int	ft_unsigned_len(unsigned int nb)
{
	size_t		size;

	size = 1;
	while ((nb /= 10))
		size++;
	return (size);
}

int	ft_hexa_len(unsigned int nb)
{
	unsigned int		len;

	len = 0;
	if (nb == 0)
	len = 1;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}
