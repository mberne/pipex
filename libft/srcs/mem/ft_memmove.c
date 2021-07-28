/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:13:12 by mberne            #+#    #+#             */
/*   Updated: 2020/11/25 14:06:11 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
