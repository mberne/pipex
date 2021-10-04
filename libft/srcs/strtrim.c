/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:46:42 by mberne            #+#    #+#             */
/*   Updated: 2021/03/05 10:56:18 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char s, char const *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (s == c[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ns;
	char	*start;
	char	*stop;

	if (s1 == 0)
		return (0);
	while (*s1 && is_sep(*s1, set) == 1)
		s1++;
	if (*s1 == '\0')
		return (ft_strdup((char *)s1));
	start = (char *)s1;
	while (*s1)
		s1++;
	s1--;
	while (*s1 && is_sep(*s1, set) == 1)
		s1--;
	s1++;
	stop = (char *)s1;
	ns = malloc(sizeof(char) * (stop - start) + 1);
	if (!ns)
		return (0);
	ft_strlcpy(ns, start, stop - start + 1);
	return (ns);
}
