/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <namalier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:11:19 by namalier          #+#    #+#             */
/*   Updated: 2024/05/05 18:35:44 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//Functions from file : ft_tolower.c
int		ft_tolower(int c);

//Functions from file : ft_strlen.c
size_t	ft_strlen(const char *c);

//Functions from file : ft_memcpy.c
void	*ft_memcpy(void *dest, const void *src, size_t n);

//Functions from file : ft_substr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);

//Functions from file : ft_strdup.c
char	*ft_strdup(const char *s);

//Functions from file : ft_memset.c
void	*ft_memset(void *s, int c, size_t n);

//Functions from file : ft_memchr.c
void	*ft_memchr(const void *s, int c, size_t n);

//Functions from file : ft_split.c
char	**ft_split(char const *s, char c);

//Functions from file : ft_strlcat.c
size_t	ft_strlcat(char *dest, const char *src, size_t size);

//Functions from file : ft_strrchr.c
char	*ft_strrchr(const char *s, int c);

//Functions from file : ft_strlcpy.c
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

//Functions from file : ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//Functions from file : ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);

//Functions from file : ft_strtrim.c

char	*ft_strtrim(char const *s1, char const *set);

//Functions from file : ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//Functions from file : ft_isprint.c
int		ft_isprint(int c);

//Functions from file : ft_isdigit.c
int		ft_isdigit(int c);

//Functions from file : ft_isascii.c
int		ft_isascii(int c);

//Functions from file : ft_isalpha.c
int		ft_isalpha(int c);

//Functions from file : ft_isalnum.c
int		ft_isalnum(int c);

//Functions from file : ft_atoi.c
int		ft_atoi(const char *str);

//Functions from file : ft_memmove.c
void	*ft_memmove(void *dest, const void *src, size_t n);

//Functions from file : ft_calloc.c
void	*ft_calloc(size_t nmb, size_t size);

//Functions from file : ft_strnstr.c
char	*ft_strnstr(const char *str, const char *tofind, size_t n);

//Functions from file : ft_strchr.c
char	*ft_strchr(const char *s, int c);

//Functions from file : ft_bzero.c
void	ft_bzero(void *s, size_t n);

//Functions from file : ft_toupper.c
int		ft_toupper(int i);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstfree(t_list **a);

#endif
