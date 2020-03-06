/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:41:23 by lryst             #+#    #+#             */
/*   Updated: 2020/02/26 20:03:53 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_print_m(int *u, size_t *count)
{
	ft_putchar_c('-', count);
	*u = *u * (-1);
	return (u);
}

void	ft_putchar_c(char u, size_t *count)
{
	write(1, &u, 1);
	*count = *count + 1;
}

void	ft_putstr_c(char *str, size_t *count)
{
	int i;

	if (str == NULL)
	{
		ft_putstr_c("(null)", count);
		return;
	}
	i = ft_strlen(str);
	write(1, str, i);
	*count = *count + i;
}
