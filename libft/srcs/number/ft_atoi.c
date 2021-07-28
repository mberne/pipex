/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:57:34 by mberne            #+#    #+#             */
/*   Updated: 2021/03/05 10:47:08 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	nb;
	int	len;

	i = 0;
	n = 1;
	nb = 0;
	len = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		n *= (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i++] - '0');
		len++;
	}
	if (len > 18 && n == (-1))
		return (0);
	else if (len > 18 && n == 1)
		return (-1);
	return (nb * n);
}
