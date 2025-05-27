/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:29:04 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:29:04 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <fcntl.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/*Structs*/

/// @brief The structure of the lists.
/// @param content The parameter void* content.
/// @param next The pointer to the next node s_list*.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*Libft Part 1*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *c);
void	*ft_memset(void *dest, int c, size_t count);
void	ft_bzero(void *dest, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
size_t	ft_strlcpy(char *dest, const char *src, size_t count);
size_t	ft_strlcat(char *dest, const char *src, size_t count);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t count);
void	*ft_memchr(const void *buf, int c, size_t count);
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
char	*ft_strnstr(const char *big, const char *little, size_t count);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *str);

/*Libft Part 2*/

char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*Libft Part 3*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*My functions*/

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(char c);
char	*ft_strcpy(char *dest, const char *src);
long	ft_atol(const char *str);
int		ft_sqrt(int nb);
int		ft_power(int base, int exp);

/*GNL*/

char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t num, size_t size);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char	*ft_free(char *final, char *temp);

#endif