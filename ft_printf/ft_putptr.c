/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:29:51 by msimoes           #+#    #+#             */
/*   Updated: 2025/05/01 19:29:19 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(size_t n)
{
	int			i;
	const char	*hex = "0123456789abcdef";

	i = 0;
	if (n > 15)
		i += ft_putptr(n / 16);
	i += ft_putchar(hex[n % 16]);
	return (i);
}

int	ft_address(size_t n)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (ft_putstr("0x") + ft_putptr(n));
}

/*
int main()
{
	char *str = "abcd";
	void *ptr = (void *)str;

	printf("%p %p", ptr);
	ft_putptr(ptr);
}
*/