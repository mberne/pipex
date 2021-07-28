NAME		=	libft.a

#List of sources
PATH_CTYPE	=	srcs/ctype/
PATH_GNL	=	srcs/gnl/
PATH_LIST	=	srcs/list/
PATH_MEM	=	srcs/mem/
PATH_NUMBER	=	srcs/number/
PATH_PUT	=	srcs/put/
PATH_STR	=	srcs/str/

SRCS_CTYPE	=	$(addprefix $(PATH_CTYPE), ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c)
SRCS_GNL	=	$(addprefix $(PATH_GNL), get_next_line.c)
SRCS_LIST	=	$(addprefix $(PATH_LIST), ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)
SRCS_MEM	=	$(addprefix $(PATH_MEM), ft_bzero.c ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c)
SRCS_NUMBER	=	$(addprefix $(PATH_NUMBER), ft_isnumber.c ft_atoi.c ft_itoa.c ft_atoi_base.c)
SRCS_PUT	=	$(addprefix $(PATH_PUT), ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c)
SRCS_STR	=	$(addprefix $(PATH_STR), ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c)

SRCS		=	$(SRCS_CTYPE) $(SRCS_GNL) $(SRCS_LIST) $(SRCS_MEM) $(SRCS_NUMBER) $(SRCS_PUT) $(SRCS_STR)

#List of includes
PATH_INC	=	includes/
HEADER		=	$(addprefix $(PATH_INC), libft.h)

#Other
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

%.o:		%.c $(HEADER)
			gcc $(CFLAGS) -c $< -o ${<:.c=.o} -I$(PATH_INC)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re