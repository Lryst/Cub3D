/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:40:15 by lryst             #+#    #+#             */
/*   Updated: 2020/02/13 16:02:42 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_struct2(t_flags *prt, size_t *count, va_list args)
{
	if (prt->flags != 0 && prt->nbr_f >= 0 &&
	prt->p != 0 && prt->nbr_p < 0 && prt->conv != 0)
		ft_just_flag(prt, count, args);
	if (prt->flags == 0 && prt->nbr_f == -1 &&
	prt->p != 0 && prt->nbr_p < 0 && prt->conv != 0)
		ft_conv(prt, count, args);
	if (prt->flags == 0 && prt->nbr_f == -1 &&
	prt->p == 0 && prt->nbr_p < 0 && prt->conv != 0)
		ft_conv(prt, count, args);
	if (prt->flags != 0 && prt->nbr_f >= 0 &&
	prt->p == 0 && prt->nbr_p < 0 && prt->conv != 0)
		ft_just_flag(prt, count, args);
	if (prt->flags == 0 && prt->nbr_f == -1 &&
	prt->p != 0 && prt->nbr_p >= 0 && prt->conv != 0)
		ft_precision(prt, count, args);
}

void	ft_check_struct(t_flags *prt, size_t *count, va_list args)
{
	if (prt->flags == 0 && prt->nbr_f >= 0 &&
	prt->p != 0 && prt->nbr_p < 0 && prt->conv != 0)
		ft_width(prt, count, args);
	if (prt->flags == 0 && prt->nbr_f >= 0 &&
	prt->p == 0 && prt->nbr_p < 0 && prt->conv != 0)
		ft_width(prt, count, args);
	if (prt->flags != 0 && prt->nbr_f >= 0 &&
	prt->p != 0 && prt->nbr_p >= 0 && prt->conv != 0)
		ft_full_flags(prt, count, args);
	if (prt->flags == 0 && prt->nbr_f >= 0 &&
	prt->p != 0 && prt->nbr_p >= 0 && prt->conv != 0)
		ft_width_p(prt, count, args);
	if (prt->flags != 0 && prt->nbr_f == -1 &&
	prt->p == 0 && prt->nbr_p < 0 && prt->conv != 0)
		ft_conv(prt, count, args);
	ft_check_struct2(prt, count, args);
}
