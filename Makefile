NAME 		= fillit

SRC_PATH 	= srcs/
OBJ_PATH	= obj/
INC_PATH 	= include/ libft/includes/

SRC_NAME	= main.c exit.c parse.c lst_set.c free.c check.c
OBJ_NAME	= $(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC			=	$(addprefix -I,$(INC_PATH))

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror
LDFLAGS		= -L libft -l ft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) $(OBJ) -o $@ && \
		printf " -->> \033[32mCompilation Success: %s\033[0m             \n" "$@"|| \
		printf " -->> \033[31mCompilation Failed: %s\033[0m              \n" "$@";

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && \
		printf " -->> \033[32mOk\033[0m: %s                       		\r" "$@" || \
		printf " -->> \033[31mKo\033[0m: %s                       		\r" "$@";

clean:
	@make clean -C libft
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@make fclean -C libft
	rm -fv $(NAME)

re: fclean all
