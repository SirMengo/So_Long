/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:05:42 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/14 14:35:54 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i - s1_len])
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
int main()
{
	char str1[] = "Hello";
	char str2[] = "World";
	printf("Joining '%s'\n", str1);
	printf("and '%s'\n", str2);
	char *dest = ft_strjoin(str1, str2);
	printf("Output: '%s'\n", dest);
}
*/