#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	if (!lst)
		return (0);
	current = lst;
	count = 1;
	while (current -> next != NULL)
	{
		current = current -> next;
		count++;
	}
	return (count);
}
