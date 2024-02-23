NAME = push_swap

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRCS = 	push_swap.c\
		operations/swap_operations.c\
		operations/push_operations.c\
		operations/rotate_operations.c\
		operations/rrotate_operations.c\
		operations/list_utils.c\
		libft/libft.a\
		printf/libftprintf.a\

$(NAME) :
	make all -C libft
	make all -C printf
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	rm -fr $(NAME)
	make fclean -C libft
	make fclean -C printf

clean :
	rm -fr $(NAME)
	make clean -C libft
	make clean -C printf

re : fclean all
