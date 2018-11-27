/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:05:51 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/26 18:08:06 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "ft_printf/ft_printf.h"

char				*ft_update(char *str, char *update);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_bchar(int n, char c);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_wstrlen(wchar_t *str);
int					ft_wchrlen(wchar_t wc);
char				*ft_strdup(const char *s1);
char				*ft_wstrdup(wchar_t *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
char				*ft_strtoupper(char *str);
char				*ft_strtolower(char *str);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
char				*ft_strccrt(const char *str, char c);
int					ft_strsch(char *str, char *to_find);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned intstart, size_t len);
char				*ft_strjoin(char const *s1, char const*s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
void				ft_putchar(char c);
void				ft_putwchar(wchar_t c);
void				ft_putstr(char const *s);
void				ft_putwstr(wchar_t *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putunsignedint(unsigned int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putwstr_fd(wchar_t *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa_base(intmax_t value, int base);
int					get_next_line(const int fd, char **line);
char				*ft_strcon(char **arr, char *c);
void				ft_clean_arr(char ***arr);
char				**ft_create_arr(int height, int width);

#endif
