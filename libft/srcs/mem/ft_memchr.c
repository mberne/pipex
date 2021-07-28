/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:14:15 by mberne            #+#    #+#             */
/*   Updated: 2021/05/27 14:08:24 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	value;

	i = 0;
	str = (unsigned char *)s;
	value = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == value)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
