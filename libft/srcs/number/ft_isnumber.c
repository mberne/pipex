#include "libft.h"

int	ft_isnumber(char *s)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	while (ft_isdigit(s[j]))
		j++;
	if (i == j)
		return (1);
	return (0);
}
