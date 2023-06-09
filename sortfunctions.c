#include "push_swap.h"

bool	checkpos(t_stack *stack, int num, bool ascending)
{
	if (ascending)
	{
		if (stack->prev->num > stack->num)
			return (num < stack->num || num > stack->prev->num);
		return (num < stack->num && num > stack->prev->num);
	}
	else
	{
		if (stack->prev->num < stack->num)
			return (num > stack->num || num < stack->prev->num);
		return (num > stack->num && num < stack->prev->num);
	}
}

bool	getrev(t_stack *stack, int num, int group, bool ascend)
{
	t_stack	*pcurr;
	t_stack	*ncurr;

	pcurr = stack->prev;
	ncurr = stack->next;
	while (true)
	{
		if (group == -1)
		{
			if (checkpos(pcurr, num, ascend) || num == pcurr->num)
				return (true);
			if (checkpos(ncurr, num, ascend) || num == ncurr->num)
				return (false);
		}
		else
		{
			if (pcurr->group == group)
				return (true);
			if (ncurr->group == group)
				return (false);
		}
		pcurr = pcurr->prev;
		ncurr = ncurr->next;
	}
}

void	setstack(t_data *data, int num, bool ascend)
{
	bool	rev;

	if (!data->stacka || data->sizea < 2 || checkpos(data->stacka, num, ascend))
		return ;
	rev = getrev(data->stacka, num, -1, ascend);
	while (!checkpos(data->stacka, num, ascend))
		operation(data, 5 + (rev * 3), false);
}
