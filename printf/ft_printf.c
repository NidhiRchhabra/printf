/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchhabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:48:16 by nchhabra          #+#    #+#             */
/*   Updated: 2022/08/05 16:45:51 by nchhabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	check_printf(char s, va_list	*args, int	*len, int *i)
{
	if (s == 's')
		ft_str(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_nbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_u(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_xx(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_xx(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_p(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

/* Here we start iterating through the string, checking
 * for the arguments to convert.
 *
 * %c Prints a single character.
 * %s Prints a string (as defined by the common C convention).
 * %p Prints the void * pointer address in hexadecimal format.
 * %d Prints a decimal (base 10) number.
 * %i Prints an integer in base 10.
 * %u Prints an unsigned decimal (base 10) number.
 * %x Prints a number in hexadecimal (base 16) lowercase format.
 * %X Prints a number in hexadecimal (base 16) uppercase format.
 * %% Prints a percent sign.
 *
 * If a %character not mentioned above is found, it will just print
 * the character. e.g. %a = a. %%a = %a.
 * It does this by moving back to check the character before it
 * by (*i)--, then moving to the printf function below.
*/

int	ft_printf(const char	*s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			check_printf(s[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)s[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
/* The ellipsis indicate that we will be using a variable number
 * of arguments in this function which is initialised by va_start.
 * If we go through the string and find a %, we go through the
 * check_printf function above to convert the argument.
 * If there is no % found, we just continue iterating and returning
 * the string. We then signal that there are no more arguments
 * with va_end, which makes the argument pointer invalid.
 */
