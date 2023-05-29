#include "libft.h"

static bool	whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	pn;

	i = 0;
	num = 0;
	pn = 1;
	if (!str)
		return (0);
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * pn);
}
