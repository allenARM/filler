/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:19:46 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 14:41:41 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "header.h"

char				*ft_update(char *str, char *update);
char				*ft_strccrt(const char *str, char c);
int					ft_isdigit(int c);
char				*ft_bchar(int n, char c);
char				*ft_strtoupper(char *str);
char				*ft_strchrfill(int len, char symbol);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *destination, int c, size_t n);
void				*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n);
void				*ft_memcpy(void *restrict dst,
		const void *restrict src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strchr(const char *str, int ch);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1,
		const char *restrict s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strstr(const char *haystack, const char *needle);
size_t				ft_strlcat(char *restrict dst,
		const char *restrict src, size_t dstsize);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strrchr(const char *src, int c);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_sizeofint(int num, int base);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					b_printf(const char *restrict s, ...);
char				*ft_makestr(char c);
int					get_next_line(const int fd, char **line);
size_t				ft_abs(long long nb);
char				*ft_itoa_base(long long value, int base);
char				*ft_itoa_base_big(long long value, int base);

#endif
