/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:14:38 by msimoes           #+#    #+#             */
/*   Updated: 2025/05/01 19:25:51 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sort_format(char const c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		i += ft_address(va_arg(ap, size_t));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		i += ft_putuns(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += sort_format(format[i + 1], ap);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
