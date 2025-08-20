/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:32:00 by msimoes           #+#    #+#             */
/*   Updated: 2025/05/01 19:26:10 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	long	j;

	j = n;
	i = 0;
	if (j < 0)
	{
		i += ft_putchar('-');
		j = -j;
	}
	if (j >= 10)
	{
		i += ft_putnbr(j / 10);
		i += ft_putnbr(j % 10);
	}
	else
		i += ft_putchar(j + '0');
	return (i);
}

/*
int main()
{
	printf("\n%d", ft_putnbr(9999999999999));

}*/
