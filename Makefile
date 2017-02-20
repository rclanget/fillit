# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-norm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 15:32:36 by dle-norm          #+#    #+#              #
#    Updated: 2016/03/15 15:32:38 by dle-norm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = src/*.c
OBJ = $(SRC:.c=.o)
INC =  -I inc/ -I libft/includes
FLAGS = -arch i386 -arch x86_64

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@gcc -c $(SRC) -I libft/ $(INC)
	@mv *.o src
	@echo "\tWARNING object don't be register in src !"
	@gcc -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "fillit: compilation done."

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft/
	@echo "fillit: objects deleted."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all
