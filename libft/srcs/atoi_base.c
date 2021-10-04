/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:24 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 15:07:01 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	else
		return (1);
}

static int	get_nb(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != str)
		i++;
	return (i);
}

static int	ft_baselen(char *base)
{
	int	baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	return (baselen);
}

static int	inbase(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	nb;

	i = 0;
	n = 1;
	nb = 0;
	if (ft_base(base) == 1)
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				n *= (-1);
			i++;
		}
		while (inbase(str[i], base) == 1)
		{
			nb = (ft_baselen(base) * nb) + get_nb(str[i], base);
			i++;
		}
	}
	return (nb *= n);
}
