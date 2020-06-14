/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:20:40 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 00:40:04 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# define SET " 012SWEN"
# define ISSPACE "\t \v \r \f"
# define FLINE "\t\n"
# define POSITION "SWEN"
# define INFO "RSNOWEAFC"

# define GNL_BUF_SIZE 4000

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct
{
	int				flags;
	int				nbr_f;
	int				p;
	int				nbr_p;
	int				conv;
}					t_flags;

void				ft_bzero(void *str, size_t i);
void				*ft_memset(void *s, int c, size_t u);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int i, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
int					ft_memlen(void *s);
char				*ft_newstring(size_t i);

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, int c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dest, char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strspn(char *set, char u);
int					ft_strspm(char *set, char u);

int					ft_isalpha(int u);
int					ft_isdigit(int u);
int					ft_isalnum(int u);
int					ft_isascii(int u);
int					ft_isprint(int u);
int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_strjoinfree_separate(char *s1, char *s2, char c);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				**ft_split_set(const char *str, char *charset);
char				*ft_itoa(int n);
int					ft_intlen(int nb);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *p, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int nb);
void				ft_putchar(char u);
void				ft_putstr(char *str);
char				*ft_strndup(const char *s, int n);
char				*ft_strdup(const char *s1);

t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **alst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));

int					ft_printf(const char *format, ...);
int					get_next_line(int fd, char **line);

void				ft_check_struct2(t_flags *prt, size_t *count, va_list args);
void				ft_check_struct(t_flags *prt, size_t *count, va_list args);

void				ft_conv(t_flags *prt, size_t *count, va_list args);

void				ft_flags_m(t_flags *prt, size_t *count, va_list args);

void				ft_flag_z(t_flags *prt, size_t *count, va_list args);

void				ft_just_flag(t_flags *prt, size_t *count, va_list args);
void				ft_full_flags_m(t_flags *prt, size_t *count, va_list args);
void				ft_full_flags(t_flags *prt, size_t *count, va_list args);

int					ft_count_nbr(const char *str, int *i);
int					ft_unsigned_len(unsigned int nb);
int					ft_hexa_len(unsigned int nb);

t_flags				*ft_is_stars(int *i, t_flags *prt, va_list args);
t_flags				*ft_is_p(const char *str, int *i, t_flags *prt,
va_list args);
t_flags				*ft_is_flags(const char *str, int *i, t_flags *prt);
t_flags				*ft_parse_conv(const char *str, int *i, t_flags *prt);
void				ft_parse(const char *str, int *i, va_list args,
size_t *count);

void				ft_percent_right(t_flags *prt, size_t *count);
void				ft_percent_left(t_flags *prt, char q, size_t *count);

void				ft_precision(t_flags *prt, size_t *count, va_list args);

void				ft_c_right(t_flags *prt, va_list args, size_t *count);
void				ft_c_left(t_flags *prt, char q, va_list args,
size_t *count);

int					*ft_print_m(int *u, size_t *count);
void				ft_putchar_c(char u, size_t *count);
void				ft_putstr_c(char *str, size_t *count);

void				ft_di_width_p(t_flags *prt, va_list args, size_t *count);
void				ft_di_left_p(t_flags *prt, char q, va_list args,
size_t *count);
void				ft_di_right(t_flags *prt, va_list args, size_t *count);
void				ft_di_left(t_flags *prt, char q, va_list args,
size_t *count);
void				ft_di_truc(t_flags *prt, size_t *count, int len, int nbr);

void				ft_maj_x_width_p(t_flags *prt, va_list args, size_t *count);
void				ft_maj_x_l_p(t_flags *prt, char q, va_list args,
size_t *count);
void				ft_maj_x_right(t_flags *prt, va_list args, size_t *count);
void				ft_maj_x_l(t_flags *prt, char q, va_list args,
size_t *count);
void				ft_maj_x_truc(t_flags *prt, int len, size_t *count);

void				ft_putnbr_hexa(unsigned int n, size_t *count);
void				ft_putnbru(unsigned int n, size_t *count);
void				ft_putnbrdi(int n, size_t *count);
void				ft_putnbr_hexa_maj(unsigned int n, size_t *count);
void				ft_putnbr_p(unsigned long long n, size_t *count);

int					ft_p_len(unsigned long long nb);
void				ft_adres(unsigned long long nb, size_t *count);
void				ft_p_right(t_flags *prt, va_list args, size_t *count);
void				ft_p_left(t_flags *prt, char q, va_list args,
size_t *count);

void				ft_s_l_space(t_flags *prt, char q, va_list args,
size_t *count);
void				ft_s_right(t_flags *prt, va_list args, size_t *count);
void				ft_s_lz(t_flags *prt, va_list args, size_t *count);

void				ft_u_left(t_flags *prt, char q, va_list args,
size_t *count);
void				ft_u_right(t_flags *prt, va_list args, size_t *count);
void				ft_u_left_p(t_flags *prt, char q, va_list args,
size_t *count);
void				ft_u_width_p2(t_flags *prt, int len, size_t *count);
void				ft_u_width_p(t_flags *prt, va_list args, size_t *count);

void				ft_x_l(t_flags *prt, char q, va_list args, size_t *count);
void				ft_x_right(t_flags *prt, va_list args, size_t *count);
void				ft_x_l_p(t_flags *prt, char q, va_list args, size_t *count);
void				ft_x_width_p2(t_flags *prt, int len, size_t *count);
void				ft_x_width_p(t_flags *prt, va_list args, size_t *count);

t_flags				fill_struct(t_flags *prt, int *i);
int					ft_printf(const char *list, ...);
void				ft_s_wp2(t_flags *prt, size_t *count, char *str);
void				ft_s_wp3(t_flags *prt, size_t *count, int len, char *str);
void				ft_s_wp(t_flags *prt, va_list args, size_t *count);

void				ft_s_lz_p2(t_flags *prt, size_t *count);
void				ft_s_lz_p(t_flags *prt, va_list args, size_t *count);

void				ft_s_w_p2(t_flags *prt, size_t *count, int i, char *str);
void				ft_s_w_p3(t_flags *prt, size_t *count, int i, char *str);
void				ft_s_w_p(t_flags *prt, va_list args, size_t *count);

void				ft_width(t_flags *prt, size_t *count, va_list args);
void				ft_width_p(t_flags *prt, size_t *count, va_list args);

#endif
