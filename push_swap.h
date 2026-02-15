/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:39:07 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/15 21:03:28 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <limits.h>
# include <bsd/string.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>

typedef struct s_list
{
	int			*content;
	struct s_list	*next;
}			t_list;

char		**ft_split(char const *s, char c);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(void *content);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char	*str);
char		*ft_substr(char const *str, unsigned int start, size_t len);
void		check_argument(char *str);
void		ft_error(void);
void		ft_freemat(char **mat);
void		add_stack(char *argv, t_list **stack_a);

#endif