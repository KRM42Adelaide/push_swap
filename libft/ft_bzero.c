#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if ((n == 0) || (!s))
		return ;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}
