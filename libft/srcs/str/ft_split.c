/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:50:39 by mberne            #+#    #+#             */
/*   Updated: 2021/03/05 10:57:54 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_countwords(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			i++;
		s++;
	}
	return (i);
}

char	**ft_free_split(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*start;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (s == 0 || !tab)
		return (0);
	while (*s)
	{
		while (*s && is_sep(*s, c) == 1)
			s++;
		start = (char *)s;
		while (*s && is_sep(*s, c) == 0)
			s++;
		if (s != start)
		{
			tab[i] = malloc(sizeof(char) * ((s - start) + 1));
			if (!tab[i])
				return (ft_free_split(tab, i));
			ft_strlcpy(tab[i++], start, s - start + 1);
		}
	}
	tab[i] = 0;
	return (tab);
}
