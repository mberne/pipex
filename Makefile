NAME		= pipex

#Sources
PATH_SRCS	= srcs/
SRCS		= $(addprefix $(PATH_SRCS), main.c)

#Includes
PATH_INC	= includes/
HEADER		= $(addprefix $(PATH_INC), pipex.h)

#Libs
LIBFT		= libft.a

#Other
OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all bonus:	libs $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -I $(PATH_INC)

libs:
			$(MAKE) -C libft
			ln -sf libft/$(LIBFT) .

%.o:		%.c	$(HEADER)
			gcc $(CFLAGS) -c $< -o ${<:.c=.o} -I $(PATH_INC)

clean:
			${MAKE} clean -C libft
			$(RM) $(OBJS)

fclean:		
			${MAKE} fclean -C libft
			$(RM) $(OBJS) $(NAME) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re libs