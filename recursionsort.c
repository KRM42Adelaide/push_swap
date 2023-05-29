#include "push_swap.h"

/*checkredundant takes op and lastop and returns a boolean value*/
static bool	checkredundant(int op, int lastop)
{
	if (op == 0)
		return (lastop == 1 || lastop == 2);
	if (op == 1)
		return (lastop == 0 || lastop == 2);
	if (op == 2)
		return (lastop == 0 || lastop == 1);
	if (op == 3)
		return (lastop == 4);
	if (op == 4)
		return (lastop == 3);
	if (op == 5)
		return (lastop == 6 || lastop == 8 || lastop == 10);
	if (op == 6)
		return (lastop == 5 || lastop == 9 || lastop == 10);
	if (op == 7)
		return (lastop >= 8 && lastop <= 10);
	if (op == 8)
		return (lastop == 5 || lastop == 9 || lastop == 7);
	if (op == 9)
		return (lastop == 6 || lastop == 8 || lastop == 7);
	if (op == 10)
		return (lastop >= 5 && lastop <= 7);
	return (false);
}
/*dupmoves duplicates a linked list of integers stored in 'moves' and
returns the duplicated list in a new linked list called 'saved'*/
static t_stack	*dupmoves(t_stack *saved, t_stack *moves)
{
	t_stack	*curr;

	freestack(saved);
	saved = NULL;
	if (!moves)
		return (saved);
	curr = moves;
	while (true)
	{
		saved = addnode(saved, newnode(curr->num));
		if (curr->next == moves)
			break ;
		curr = curr->next;
	}
	return (saved);
}
/**/
void	recursionsort(t_data *data, int rec, int lstop, int maxrec)
{
	static t_stack	*moves = NULL;
	t_stack			*curr;

	if (rec > maxrec || (data->movenum != 0 && rec >= data->movenum))
		return ;
	curr = newnode(0);
	moves = addnode(moves, curr);
	while (curr->num <= 10)
	{
		if (!checkredundant(curr->num, lstop) && operation(data, curr->num, true))
		{
			if (checksort(data))
			{
				data->moves = dupmoves(data->moves, moves);
				data->movenum = rec;
				undo(data, curr->num);
				break ;
			}
			recursionsort(data, rec + 1, curr->num, maxrec);
			undo(data, curr->num);
		}
		curr->num++;
	}
	moves = removenode(moves->prev);
	free(curr);
}
