/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:46:49 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 13:48:48 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	value;
	size_t	len;

	i = 0;
	value = (char)c;
	len = ft_strlen((char *)s);
	while (i <= len)
	{
		if (s[i] == value)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	value;

	i = ft_strlen(s);
	value = (char)c;
	if (s[i] == value)
		return ((char *)&s[i]);
	while (--i >= 0)
		if (s[i] == value)
			return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (src == 0)
	{
		dst = 0;
		return (0);
	}
	j = ft_strlen(src);
	if (dstsize == 0)
		return (j);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
