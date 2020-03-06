/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:41:18 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 14:36:22 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_right(t_flags *prt, va_list args, size_t *count)
{
	int n;

	n = 0;
	ft_putchar_c(va_arg(args, int), count);
	while (n++ < ((prt->nbr_f) - 1))
		ft_putchar_c(' ', count);
}

void	ft_c_left(t_flags *prt, char q, va_list args, size_t *count)
{
	int n;

	n = 0;
	while (n++ < ((prt->nbr_f) - 1))
		ft_putchar_c(q, count);
	ft_putchar_c(va_arg(args, int), count);
}
