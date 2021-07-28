/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:11:14 by mberne            #+#    #+#             */
/*   Updated: 2020/11/25 10:34:29 by mberne           ###   ########lyon.fr   */
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
