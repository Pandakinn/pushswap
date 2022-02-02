/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:29:59 by darian            #+#    #+#             */
/*   Updated: 2022/01/05 18:32:34 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <ctype.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void			ft_putnbr(int n);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(char const *s, char c);
char	*ft_strncpy(char *dest, char const *src, size_t n);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strncat(char *dest, char const *src, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlen(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strcat(char *dest, const char *src);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char const *str, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *nptr);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_isprint(int c);
int		ft_isascii(int c);
size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list **lst, void (*del)(int *));
void	ft_lstdelcontent(int *content);
void	ft_lstclear(t_list **lst, void (*del)(int *));
void	ft_lstiter(t_list *lst, void (*f)(int *));
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int *));
void	ft_lstprint(t_list *li);
void	ft_lstdelindex(t_list *lst, void (*del)(int *), int index);
int		ft_lstisin(t_list *li, int nb);

int				count_args(char const *str);
int				is_type(char c);

void			ft_putstr(char *s);
void			ft_putnbr_unsigned(unsigned int n);
char			*ft_itoa_llu(unsigned long long nb);
char			*str_rev(char *str);

int				size_nb_base(unsigned int nb, unsigned int base_len);
unsigned int	val(char c, int lower);
int				str_islower(char *str);
int				size_nb_base_llu(unsigned long long nb, int base_len);
long long		val_llu(char c);
char			*convert_hexa(char *nb, int *len, int maj);
int				ft_printf(const char *str, ...);
int				size_nb(int nbr);
int				size_nb_unsigned(unsigned int nbr);
int				print_pointer(unsigned long long pointer, int *nb);
char			*base_converter_llu(char *nb, char *base_from,
					char *base_to, int *len);
char			*negative_dec_to_hex(long nb);
char			*str_rev(char *str);
char			*base_converter(char *nb, char *base_from,
					char *base_to, int *len);
int				call_function(va_list args, char const *str, int i, int *nb);


#endif