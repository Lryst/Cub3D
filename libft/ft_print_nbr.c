/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:41:44 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 14:37:01 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned int n, size_t *count)
{
	if (n > 15)
	{
		ft_putnbr_hexa((n / 16), count);
		ft_putnbr_hexa((n % 16), count);
	}
	else if (n < 10)
		ft_putchar_c(n + '0', count);
	else
		ft_putchar_c(n - 10 + 'a', count);
}

void	ft_putnbru(unsigned int n, size_t *count)
{
	if (n > 9)
	{
		ft_putnbru(n / 10, count);
		ft_putnbru(n % 10, count);
	}
	else
		ft_putchar_c(n + 48, count);
}

void	ft_putnbrdi(int n, size_t *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count = *count + 11;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_c('-', count);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbrdi(n / 10, count);
			ft_putnbrdi(n % 10, count);
		}
		else
			ft_putchar_c(n + 48, count);
	}
}

void	ft_putnbr_hexa_maj(unsigned int n, size_t *count)
{
	if (n > 15)
	{
		ft_putnbr_hexa_maj((n / 16), count);
		ft_putnbr_hexa_maj((n % 16), count);
	}
	else if (n < 10)
		ft_putchar_c(n + '0', count);
	else
		ft_putchar_c(n - 10 + 'A', count);
}

void	ft_putnbr_p(unsigned long long n, size_t *count)
{
	if (n > 15)
	{
		ft_putnbr_p((n / 16), count);
		ft_putnbr_p((n % 16), count);
	}
	else if (n < 10)
		ft_putchar_c(n + '0', count);
	else
		ft_putchar_c(n - 10 + 'a', count);
}
