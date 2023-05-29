#include "push_swap.h"

/*initdata sets the initial values of the struct t_data*/
static void	initdata(t_data *data)
{
	data->stacka = NULL;
	data->stackb = NULL;
	data->sizea = 0;
	data->sizeb = 0;
	data->moves = NULL;
	data->movenum = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

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

	freedata(&data);
	return (0);
}
//1. t_data is defined to hold some data 
//2. data is initialized by initdata which sets initial values for the struct
//3. command-line arguments are loaded into the 'data' structure by loadargs
//3b. error message is written if the loading fails and false is returned
//4. checksort checks if the data needs to be sorted. If not, function enters the if statement
//5. if size of the data is less than 7, recursionsort sorts the data
//6. If the size of the data is 7 or greater, groupsort sorts the data
/*7. After sorting/after loading(If sorting is not required) data.moves structure is passed 
	to printmoves to print the moves made during printing process*/
//8.freedata frees any dynamically allocated memory used by the 'data' structure 