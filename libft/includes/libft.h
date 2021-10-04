/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:33:45 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 15:20:05 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 50

# include <stdlib.h>
# include <unistd.h>

/*
** ATOI BASE
*/
int			ft_atoi_base(char *str, char *base);

/*
** ATOI ITOA
*/
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
int			ft_isnumber(char *s);

/*
** C TYPE
*/
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

/*
** GET NEXT LINE
*/
int			get_next_line(int fd, char **line);

/*
** LIST
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));

/*
** MEM
*/
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);

/*
** PUT FD
*/
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

/*
** SPLIT
*/
char		**ft_split(char const *s, char c);

/*
** STR
*/
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*
** STRJOIN
*/
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free_s1(char const *s1, char const *s2);
char		*ft_strjoin_free_s2(char const *s1, char const *s2);
char		*ft_strjoin_free(char const *s1, char const *s2);

/*
** STRTRIM
*/
char		*ft_strtrim(char const *s1, char const *set);

#endif
