#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*curr;

	newlist = NULL;
	while (lst != NULL)
	{
		curr = ft_lstnew((*f)(lst -> content));
		if (!curr)
		{
			while (newlist != NULL)
			{
				curr = newlist -> next;
				(*del)(newlist -> content);
				free(newlist);
				newlist = curr;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&newlist, curr);
		lst = lst -> next;
	}
	return (newlist);
}
