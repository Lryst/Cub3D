/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:42:10 by lryst             #+#    #+#             */
/*   Updated: 2020/02/26 20:03:53 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_left(t_flags *prt, char q, va_list args, size_t *count)
{
	unsigned int u;
	unsigned int c;
	unsigned int n;
	unsigned int i;

	n = 0;
	u = va_arg(args, unsigned int);
	c = ft_unsigned_len(u);
	if (u == 0 && prt->nbr_p == 0)
		return;
	if ((unsigned int)(prt->nbr_f) > c)
	{
		i = (prt->nbr_f) - c;
		while (n++ < i)
			ft_putchar_c(q, count);
	}
	ft_putnbru(u, count);
}

void	ft_u_right(t_flags *prt, va_list args, size_t *count)
{
	unsigned int	u;
	int				c;
	int				n;

	n = 0;
	u = va_arg(args, unsigned int);
	c = ft_unsigned_len(u);
	ft_putnbru(u, count);
	while (n++ < ((prt->nbr_f) - c))
		ft_putchar_c(' ', count);
}

void	ft_u_left_p(t_flags *prt, char q, va_list args, size_t *count)
{
	unsigned int u;
	unsigned int c;
	unsigned int n;

	n = 0;
	u = va_arg(args, unsigned int);
	c = ft_unsigned_len(u);
	if (u == 0 && prt->nbr_p == 0)
		return;
	if (c < (unsigned int)prt->nbr_p)
	{
		while (n++ < ((unsigned int)(prt->nbr_p) - c))
			ft_putchar_c(q, count);
	}
	ft_putnbru(u, count);
}

void	ft_u_width_p2(t_flags *prt, int len, size_t *count)
{
	int i;

	i = 0;
	if (prt->nbr_p < len)
	{
		while (i++ < ((prt->nbr_f) - len))
			ft_putchar_c(' ', count);
	}
	else if (prt->nbr_p >= len)
	{
		while (i++ < ((prt->nbr_f - prt->nbr_p)))
			ft_putchar_c(' ', count);
		i = 0;
		while (i++ < ((prt->nbr_p) - len))
			ft_putchar_c('0', count);
	}
}

void	ft_u_width_p(t_flags *prt, va_list args, size_t *count)
{
	int				len;
	unsigned int	nbr;
	int				i;

	i = 0;
	nbr = va_arg(args, unsigned int);
	len = ft_unsigned_len(nbr);
	if (nbr == 0 && prt->nbr_p == 0)
	{
		while (i++ < prt->nbr_f)
			ft_putchar_c(' ', count);
		return;
	}
	if (prt->nbr_f > 0)
		ft_u_width_p2(prt, len, count);
	ft_putnbru(nbr, count);
}
