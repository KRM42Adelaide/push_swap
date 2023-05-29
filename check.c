#include "push_swap.h"

/*Checks if the stack represented by the 'data' parameter is sorted in 
ascending order*/
bool	checksort(t_data *data)
{
	t_stack	*curr;

	if (data->sizeb != 0)
		return (false);
	curr = data->stacka;
	while (curr->next != data->stacka)
	{
		if (curr->num > curr->next->num)
			return (false);
		curr = curr->next;
	}
	return (true);
}
