NAME = push_swap

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g -fsanitize=address -fsanitize=undefined

SRCS = 	push_swap.c\
		sorting.c\
		\
		operations/swap.c\
		operations/push.c\
		operations/rotate.c\
		operations/rrotate.c\
		\
		utils/list_utils_1.c\
		utils/list_utils_2.c\
		utils/custom_atoi.c\
		utils/int_utils.c\
		utils/errors.c\
		utils/array.c\
		utils/frees.c\
		\
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
