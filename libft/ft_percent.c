/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:41:07 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 14:28:52 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent_right(t_flags *prt, size_t *count)
{
	int n;

	n = 0;
	ft_putchar_c('%', count);
	while (n++ < ((prt->nbr_f) - 1))
		ft_putchar_c(' ', count);
}

void	ft_percent_left(t_flags *prt, char q, size_t *count)
{
	int n;

	n = 0;
	while (n++ < ((prt->nbr_f) - 1))
		ft_putchar_c(q, count);
	ft_putchar_c('%', count);
}
