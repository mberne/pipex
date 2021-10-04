NAME		=	libft.a

#Sources
PATH_SRC	=	srcs/
SRC			=					\
				atoi_base.c		\
				atoi_itoa.c		\
				c_type.c		\
				get_next_line.c	\
				list_1.c		\
				list_2.c		\
				mem_write.c		\
				mem.c			\
				put_fd.c		\
				split.c			\
				str_1.c			\
				str_2.c			\
				strjoin.c		\
				strtrim.c		\

#Includes
PATH_INC	=	includes/
HEADER		=	$(addprefix $(PATH_INC), libft.h)

#Objects
PATH_OBJ	=	objs/
OBJ			=	$(addprefix $(PATH_OBJ), $(SRC:.c=.o))

#Other
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(PATH_OBJ)%.o:		$(PATH_SRC)%.c $(HEADER)
					@mkdir -p $(dir $@)
					gcc $(CFLAGS) -c $< -o $@ -I $(PATH_INC)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re