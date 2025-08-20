/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:41:01 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 22:49:16 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *str, size_t n);
char	*ft_strdup(const char *src);

#endif