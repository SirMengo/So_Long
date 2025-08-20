/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:25:20 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 13:52:18 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		j;

	j = ft_strlen((char *)src);
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main()
{
	char str1[] = "Hello World!";
	printf("Copying the string '%s'\n", str1);
	char *copy = ft_strdup(str1);
	printf("Output: '%s'\n", copy);
}
*/