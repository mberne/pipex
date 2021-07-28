#include "libft.h"

int	ft_base(char *base)
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

int	get_nb(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != str)
		i++;
	return (i);
}

int	ft_baselen(char *base)
{
	int	baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	return (baselen);
}

int	inbase(char str, char *base)
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
