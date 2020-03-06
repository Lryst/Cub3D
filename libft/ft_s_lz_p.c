/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lz_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:04:06 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 15:04:08 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_lz_p2(t_flags *prt, size_t *count)
{
	int		u;
	char	*null;

	null = "(null)";
	u = -1;
	if (6 >= (prt->nbr_p))
	{
		while (++u < (prt->nbr_p))
			ft_putchar_c(null[u], count);
	}
	else if (6 < (prt->nbr_p))
		ft_putstr_c("(null)", count);
}

void	ft_s_lz_p(t_flags *prt, va_list args, size_t *count)
{
	int		u;
	char	*s;
	int		c;

	u = -1;
	s = va_arg(args, char*);
	if (s == NULL)
		ft_s_lz_p2(prt, count);
	else
	{
		c = ft_strlen(s);
		if (c > (prt->nbr_p))
		{
			while (++u < (prt->nbr_p))
				ft_putchar_c(s[u], count);
		}
		else if (c <= (prt->nbr_p))
			ft_putstr_c(s, count);
	}
}
