#include "push_swap.h"

static void	initdata(t_data *data)
{
	data->stacka = NULL;
	data->stackb = NULL;
	data->sizea = 0;
	data->sizeb = 0;
	data->moves = NULL;
	data->movenum = 0;
}

static void	checkmoves(int argc, char **argv, t_stack *moves)
{
	t_data	data;
	t_stack	*curr;

	initdata(&data);
	loadargs(&data, argc, argv);
	if (moves != NULL)
	{
		curr = moves;
		while (true)
		{
			operation(&data, curr->num, true);
			if (curr->next == moves)
				break ;
			curr = curr->next;
		}
	}
	if (checkksort(&data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freedata(&data);
}

int	main(int argc, char **argv)
{
	t_data	data; 

	if (argc == 1) 
		return (0);
	initdata(&data); 
	if (!loadargs(&data, argc, argv)) 
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!checksort(&data)) 
	{ 
		if (data.sizea < 7)
			recursionsort(&data, 1, -1, (data.sizea * data.sizea) / 3); 
		else
			groupsort(&data); 
	}
	printmoves(data.moves); 
	checkmoves(argc, argv, data.moves);  
	freedata(&data); 
	return (0);
}
//1. checks that number of arguments is 1 (meaning no additional arguments were passed)
//2. initdata initializes the 'data' struct
//3. loadargs loads the arguments into the 'data' struct
//4. if loadargs returns false, an error message string is printed and zero is returned
//4. checksort checks if the data needs to be sorted
//4a. if not (meaning checksort returns false) function checks if size of the array sizea in data is less than 7. )
//if so, recursionsort sorts that data
// if size of data.sizea is 7 or more, groupsort sorts the data
//5. data.moves array is passed to printmoves to print the moves made during sorting
//6. checkmoves checks the moves against the arguments
//freedata frees any allocated memory in the data structure