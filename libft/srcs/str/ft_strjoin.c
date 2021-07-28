/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:04:28 by mberne            #+#    #+#             */
/*   Updated: 2021/03/05 10:53:40 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ns;
	size_t	lens1;
	size_t	lens2;

	i = -1;
	j = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	ns = malloc(sizeof(char) * ((lens1 + lens2 + 1)));
	if (!ns)
		return (0);
	while (++i < lens1)
		ns[i] = s1[i];
	while (++j < lens2)
		ns[i + j] = s2[j];
	ns[i + j] = '\0';
	free((char *)s1);
	return (ns);
}
