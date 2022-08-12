/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchhabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:45:50 by nchhabra          #+#    #+#             */
/*   Updated: 2022/07/08 09:47:40 by nchhabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_nbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len);
		ft_nbr(n * -1, len);
	}
	else
	{
		if (n > 9)
			ft_nbr(n / 10, len);
		ft_putchar_len(n % 10 + '0', len);
	}
}

/* If int n is minimum size, return that value.
 * If int n is less than zero, print a minus
 * before the length.
 * Multiply the negative number by -1 to create
 * a positive number.
 * If the value of int n is more than a single
 * digit, divide by ten until it is a single
 * digit.*/
