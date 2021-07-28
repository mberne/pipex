/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:12:44 by mberne            #+#    #+#             */
/*   Updated: 2020/11/25 11:07:00 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
