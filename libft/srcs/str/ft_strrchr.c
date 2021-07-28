/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:20:08 by mberne            #+#    #+#             */
/*   Updated: 2021/05/27 14:06:42 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
