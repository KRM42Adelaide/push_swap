#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		slen;

	i = 0;
	slen = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * slen + 1);
	if (!ptr)
		return (NULL);
	while (i < slen)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
