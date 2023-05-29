NAME = push_swap
BONUS = checker
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIB = libft
SOURCES = loadargs.c \
		  recursionsort.c \
		  groupsort.c \
		  sortfunctions.c \
		  mainoperations.c \
		  stackoperations.c \
		  stackfunctions.c \
		  check.c \
		  freedata.c \
		  print.c 
HEADERS = push_swap.h

all: $(NAME) $(BONUS)

$(NAME): $(SOURCES)
	make -C $(LIB)
	$(CC) $(FLAGS) $(NAME).c $(SOURCES) -L$(LIB) -lft -o $(NAME)
	
$(BONUS): $(SOURCES)
	$(CC) $(FLAGS) $(BONUS).c $(SOURCES) -L$(LIB) -lft -o $(BONUS)

clean:
	make clean -C $(LIB)
	rm $(NAME) $(BONUS)

fclean:
	make fclean -C $(LIB)
	rm $(NAME) $(BONUS)

re: fclean all

.PHONY:
	all clean fclean re
