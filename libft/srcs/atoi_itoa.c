/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:57:34 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 15:07:16 by mberne           ###   ########lyon.fr   */
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
	return (nb * n);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nb;
	int		len;

	i = 0;
	sign = 1;
	nb = 0;
	len = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i++] - '0');
		len++;
	}
	return (nb * sign);
}

int	ft_isnumber(char *s)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	if (s[0] == '-')
		j++;
	if ((i == 1 && j == 1) || i == 0)
		return (0);
	while (ft_isdigit(s[j]))
		j++;
	if (i == j)
		return (1);
	return (0);
}
