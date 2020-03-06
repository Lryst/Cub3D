/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:42:29 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 14:28:52 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	fill_struct(t_flags *prt, int *i)
{
	prt->flags = 0;
	prt->nbr_f = -1;
	prt->p = 0;
	prt->nbr_p = -1;
	prt->conv = 0;
	*i = *i + 1;
	return (*prt);
}

int		ft_printf(const char *list, ...)
{
	va_list	args;
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, list);
	while (list[i])
	{
		if (list[i] == '%')
			ft_parse(list, &i, args, &count);
		else
		{
			count++;
			ft_putchar(list[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
