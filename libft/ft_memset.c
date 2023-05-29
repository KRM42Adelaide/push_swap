#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!p)
		return (NULL);
	while (i < len)
	{
		*(unsigned char *)(p + i) = (unsigned char)c;
		i++;
	}
	return (p);
}
