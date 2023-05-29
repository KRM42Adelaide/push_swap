#include "libft.h"

static bool	checkmatch(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || len == 0)
		return (NULL);
	if (!s2 || !s2[0])
		return ((char *)s1);
	len -= ft_strlen(s2);
	if (len > 0)
	{
		while (s1[i] != '\0' && i <= len)
		{
			if (checkmatch((char *)(s1 + i), (char *)s2))
				return ((char *)(s1 + i));
			i++;
		}
	}
	return (NULL);
}
