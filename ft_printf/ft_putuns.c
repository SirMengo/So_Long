/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:32:00 by msimoes           #+#    #+#             */
/*   Updated: 2025/05/01 19:26:29 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putuns(n / 10);
		i += ft_putuns(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

/*
int main()
{
	int i = 59;
	printf("%u \n", i);
	printf("\n%d", ft_putuns(i));
}
*/