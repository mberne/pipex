/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:45:44 by mberne            #+#    #+#             */
/*   Updated: 2021/03/05 10:51:17 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
