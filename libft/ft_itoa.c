#include "libft.h"

static int	getsize(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	getdigit(int n, int index)
{
	int	mod;
	int	pn;

	mod = 1;
	pn = 1;
	if (n < 0)
		pn = -1;
	while (index > 1)
	{
		mod *= 10;
		index--;
	}
	return ((n / mod) % 10 * pn);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		size;

	i = 0;
	size = getsize(n);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		i = 1;
	}
	while (size - i > 0)
	{
		ptr[i] = '0' + getdigit(n, size - i);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
