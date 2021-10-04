/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:12:44 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 13:32:21 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	unsigned char	*string;
	size_t			i;

	value = (unsigned char)c;
	string = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		string[i] = value;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	value;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	value = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == value)
			return (&s1[i + 1]);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	if (src > dst)
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			s1[i] = s2[i];
	}
	return (dst);
}
