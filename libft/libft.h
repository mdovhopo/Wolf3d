/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:30:39 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/03 19:49:18 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** get_next_line() stuff
*/

# define END_IS_ENDL(x) (x == '\n' ? 1 : 0)
# define END_IS_NULL(x) (x == '\0' ? 1 : 0)
# define STOP_READING break ;
# define CHECK_ERRORS(fd ,line, buff) (fd < 0 || !line || read(fd, buff, 0) < 0)
# define CHECK_IF_EXIT(d, f_ch, r_b) ((d == NULL || f_ch == '\0') && r_b == 0)
# define ERROR -1
# define SUCCESS_END 0
# define BUFF_SIZE 16

typedef struct	s_gnl
{
	int				fd;
	char			*data;
	struct s_gnl	*next;
}				t_gnl;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** vectors
*/

typedef struct	s_vec2
{
	double			x;
	double			y;
}				t_vec2;

typedef struct	s_vec3
{
	double			x;
	double			y;
	double			z;
}				t_vec3;

typedef struct	s_intvec2
{
	int		x;
	int		y;
}				t_intvec2;

typedef unsigned int		t_uint;

t_vec2			ft_vec2(double x, double y);
t_vec3			ft_new_vec3(double x, double y, double z);
t_vec2			ft_add_vec2(t_vec2 v1, t_vec2 v2);
t_vec3			ft_add_vec3(t_vec3 v1, t_vec3 v2);
t_vec2			ft_sub_vec2(t_vec2 v1, t_vec2 v2);
t_vec3			ft_sub_vec3(t_vec3 v1, t_vec3 v2);
void			ft_rev_vec2(t_vec2 *v);
void			ft_rev_vec3(t_vec3 *v);
t_intvec2		ft_new_intvec2(int x, int y);

/*
** dealing with lists
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdelone(t_list **alst,
								void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst,
								void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
** dealing with memory
*/

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst,
					const void *src, size_t n);
void			*ft_memccpy(void *dst,
					const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp (const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
** string processing fuctions
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
size_t			ft_count_words(const char *s, char c);
int				get_next_line(const int fd, char **line);

/*
** put smth to standart output
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_make_coffee(int n);

/*
** some usefull stuff
*/

void			ft_show_binary(unsigned int x);
int				ft_atoi16(const char *s);
double			ft_map(double s, t_vec2 a, t_vec2 b);

/*
** detect character from some range
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** graphics stuff
*/

int				ft_rgb(int r, int g, int b);

#endif
