/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:41:28 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 00:43:41 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di_truc(t_flags *prt, size_t *count, int len, int nbr)
{
	int i;

	i = 0;
	if (nbr >= 0)
	{
		while (i++ < ((prt->nbr_f - prt->nbr_p)))
			ft_putchar_c(' ', count);
		i = 0;
		while (i++ < ((prt->nbr_p) - len))
			ft_putchar_c('0', count);
	}
	if (nbr < 0)
	{
		while (i++ < ((prt->nbr_f - prt->nbr_p) - 1))
			ft_putchar_c(' ', count);
		ft_putchar_c('-', count);
		nbr = -nbr;
		i = 0;
		while (i++ < ((prt->nbr_p) - len + 1))
			ft_putchar_c('0', count);
	}
	ft_putnbrdi(nbr, count);
}

void	ft_di_left(t_flags *prt, char q, va_list args, size_t *count)
{
	int u;
	int c;
	int n;

	n = 0;
	u = va_arg(args, int);
	c = ft_intlen(u);
	if (u == 0 && prt->nbr_f == 0 && prt->p != 0 && prt->nbr_p == 0)
	{
		while (n++ < prt->nbr_f)
			ft_putchar_c(' ', count);
		return ;
	}
	if (u < 0 && prt->flags == 1)
		ft_print_m(&u, count);
	while (n++ < ((prt->nbr_f) - c))
		ft_putchar_c(q, count);
	if (u < 0 && prt->flags == 0)
		ft_print_m(&u, count);
	ft_putnbrdi(u, count);
}

void	ft_di_right(t_flags *prt, va_list args, size_t *count)
{
	int u;
	int n;
	int c;

	n = 0;
	u = va_arg(args, int);
	c = ft_intlen(u);
	ft_putnbrdi(u, count);
	while (n++ < ((prt->nbr_f) - c))
		ft_putchar_c(' ', count);
}

void	ft_di_left_p(t_flags *prt, char q, va_list args, size_t *count)
{
	int nbr;
	int len;
	int i;

	i = 0;
	nbr = va_arg(args, int);
	len = ft_intlen(nbr);
	if (nbr == 0 && prt->nbr_p == 0)
		return ;
	if (nbr >= 0)
	{
		while (i++ < ((prt->nbr_p) - len))
			ft_putchar_c(q, count);
	}
	if (nbr < 0)
	{
		ft_putchar_c('-', count);
		nbr = nbr * (-1);
		while (i++ < ((prt->nbr_p) - (len - 1)))
			ft_putchar_c(q, count);
	}
	ft_putnbrdi(nbr, count);
}

void	ft_di_width_p(t_flags *prt, va_list args, size_t *count)
{
	int len;
	int nbr;
	int i;

	i = 0;
	nbr = va_arg(args, int);
	len = ft_intlen(nbr);
	if (nbr == 0 && prt->nbr_p == 0)
	{
		i = 0;
		while (i++ < prt->nbr_f)
			ft_putchar_c(' ', count);
		return ;
	}
	if (prt->nbr_p >= len)
		ft_di_truc(prt, count, len, nbr);
	if (prt->nbr_p < len)
	{
		while (i++ < ((prt->nbr_f) - len))
			ft_putchar_c(' ', count);
		ft_putnbrdi(nbr, count);
	}
}
