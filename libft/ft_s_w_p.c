/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_w_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:03:31 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 15:04:36 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_w_p2(t_flags *prt, size_t *count, int i, char *str)
{
	if (prt->nbr_p < 6)
	{
		while (i++ < ((prt->nbr_f) - (prt->nbr_p)))
			ft_putchar_c(' ', count);
		i = -1;
		while (++i < prt->nbr_p)
			ft_putchar_c(str[i], count);
	}
	else if (prt->nbr_p >= 6)
	{
		i = 0;
		while (i++ < ((prt->nbr_f - prt->nbr_p)))
			ft_putchar_c(' ', count);
		i = 0;
		while (i++ < ((prt->nbr_p) - 6))
			ft_putchar_c(' ', count);
		ft_putstr_c(str, count);
	}
}

void	ft_s_w_p3(t_flags *prt, size_t *count, int i, char *str)
{
	int len;

	len = ft_strlen(str);
	if (prt->nbr_p < len)
	{
		while (i++ < ((prt->nbr_f) - (prt->nbr_p)))
			ft_putchar_c(' ', count);
		i = -1;
		while (++i < prt->nbr_p)
			ft_putchar_c(str[i], count);
	}
	else if (prt->nbr_p >= len)
	{
		i = 0;
		while (i++ < ((prt->nbr_f - prt->nbr_p)))
			ft_putchar_c(' ', count);
		i = 0;
		while (i++ < ((prt->nbr_p) - len))
			ft_putchar_c(' ', count);
		ft_putstr_c(str, count);
	}
}

void	ft_s_w_p(t_flags *prt, va_list args, size_t *count)
{
	char	*str;
	char	*null;

	str = va_arg(args, char*);
	null = "(null)";
	if (str != NULL)
		ft_s_w_p3(prt, count, 0, str);
	if (str == NULL)
		ft_s_w_p2(prt, count, 0, null);
}
