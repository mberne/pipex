NAME		=	pipex

#Sources
PATH_SRC	=	srcs/
SRC			=					\
				main.c			\
				command_path.c	\

#Includes
PATH_INC	=	includes/
HEADER		=	$(addprefix $(PATH_INC), pipex.h)

#Objects
PATH_OBJ	=	objs/
OBJ			=	$(addprefix $(PATH_OBJ), $(SRC:.c=.o))

#Libs
LIBFT		= libft.a

#Other
CFLAGS		= -Wall -Wextra -Werror

all bonus:	libs $(NAME)

$(PATH_OBJ)%.o:		$(PATH_SRC)%.c	$(HEADER) $(LIBFT)
			@mkdir -p $(dir $@)
			gcc $(CFLAGS) -c $< -o $@ -I $(PATH_INC)

$(NAME):	$(OBJ) $(LIBFT)
			gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -I $(PATH_INC)

libs:
			$(MAKE) -C libft
			ln -sf libft/$(LIBFT) .

clean:
			${MAKE} clean -C libft
			rm -f $(OBJS)

fclean:		
			${MAKE} fclean -C libft
			rm -f $(OBJS) $(NAME) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re libs