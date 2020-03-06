/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:41:52 by lryst             #+#    #+#             */
/*   Updated: 2020/02/26 20:03:53 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_len(unsigned long long nb)
{
	int len;

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

void	ft_adres(unsigned long long nb, size_t *count)
{
	ft_putstr_c("0x", count);
	ft_putnbr_p(nb, count);
}

void	ft_p_right(t_flags *prt, va_list args, size_t *count)
{
	unsigned long long	adres;
	int					len;
	int					n;

	n = 0;
	adres = va_arg(args, unsigned long long);
	len = ft_p_len(adres) + 2;
	ft_adres(adres, count);
	while (n + len < (prt->nbr_f))
	{
		ft_putchar_c(' ', count);
		n++;
	}
}

void	ft_p_left(t_flags *prt, char q, va_list args, size_t *count)
{
	int					n;
	void				*a;
	unsigned long long	adres;
	int					len;

	n = 0;
	a = va_arg(args, void *);
	adres = (unsigned long long)(a);
	if (a == NULL && prt->p != 0 && prt->nbr_p == 0)
	{
		while (n++ < (prt->nbr_f) - 2)
			ft_putchar_c(q, count);
		ft_putstr_c("0x", count);
		return;
	}
	len = ft_p_len(adres) + 2;
	while (n++ < (prt->nbr_f) - len)
		ft_putchar_c(q, count);
	ft_adres(adres, count);
}
