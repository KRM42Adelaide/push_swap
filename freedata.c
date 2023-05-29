#include "push_swap.h"

void	freestack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!stack)
		return ;
	curr = stack;
	while (true)
	{
		next = curr->next;
		free(curr);
		if (next == stack)
			break ;
		curr = next;
	}
}

void	freedata(t_data *data)
{
	freestack(data->stacka);
	freestack(data->stackb);
	freestack(data->moves);
}
