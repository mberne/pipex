/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:01:48 by mberne            #+#    #+#             */
/*   Updated: 2021/03/05 10:53:56 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (lendst >= dstsize)
		return (dstsize + lensrc);
	while (src[i] && (i + lendst) < dstsize - 1)
	{
		dst[i + lendst] = src[i];
		i++;
	}
	dst[i + lendst] = '\0';
	return (lensrc + lendst);
}
