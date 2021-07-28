/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:18:58 by mberne            #+#    #+#             */
/*   Updated: 2021/05/27 14:06:26 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
