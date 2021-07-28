/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:56:43 by mberne            #+#    #+#             */
/*   Updated: 2021/03/05 10:48:22 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int n)
{
	long int	i;

	i = 0;
	if (n <= 0)
	{
		n *= (-1);
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	long int	i;
	int			j;

	i = n;
	j = ft_intlen(n) - 1;
	result = malloc(sizeof(char) * (ft_intlen(i) + 1));
	if (!result)
		return (0);
	if (i < 0)
	{
		result[0] = '-';
		i = -i;
	}
	else if (i == 0)
		result[0] = '0';
	while (i > 0)
	{
		result[j--] = i % 10 + '0';
		i /= 10;
	}
	result[ft_intlen(n)] = '\0';
	return (result);
}
