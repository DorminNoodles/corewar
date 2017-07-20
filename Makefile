VM_NAME = corewar
SRC =		main.c						\
			init.c						\
			error.c						\
			debug.c						\
			sti.c						\
			ld.c						\
			live.c						\
			add.c						\
			and.c						\
			op.c

SRCS = $(addprefix srcs/, $(SRC))
INC = -I includes -I libft/includes
OBJ = $(SRC:.c=.o)
FLAGS = #-Wall -Wextra -Werror

all : $(VM_NAME)

$(VM_NAME) : $(OBJ)
	@echo "fuck"
	make -C libft/
	$(CC) -g $(OBJ) $(INC) libft/libft.a -o build/$(VM_NAME)

%.o : srcs/%.c
	$(CC) -g -c $< $(FLAGS) $(INC) -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)
