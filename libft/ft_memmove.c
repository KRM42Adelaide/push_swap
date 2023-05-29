#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (i < len)
	{
		if (dst > src)
			j = len - 1 - i;
		else
			j = i;
		*(char *)(dst + j) = *(char *)(src + j);
		i++;
	}
	return (dst);
}
