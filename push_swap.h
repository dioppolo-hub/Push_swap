/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:39:07 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/20 19:33:48 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				content;
	struct s_list	*next;
}			t_list;

char		**ft_split(char const *s, char c);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char	*str);
char		*ft_substr(char const *str, unsigned int start, size_t len);
void		check_argument(char *str);
void		ft_error(void);
void		ft_freemat(char **mat);
void		add_stack(char *argv, t_list **stack_a);
int			sa(t_list **stack_a);
int			sb(t_list **stack_b);
int			ss(t_list **stack_a, t_list **stack_b);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			pb(t_list **stack_a, t_list **stack_b);
int			pa(t_list **stack_a, t_list **stack_b);
void		ft_lstdelone(t_list *lst);
int			ra(t_list **stack_a);
int			rb(t_list **stack_b);
int			rr(t_list **stack_a, t_list **stack_b);
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);
int			*indice_stack(t_list **stack, int size);
int			ft_lstsize(t_list *lst);
void		print_tmparr(int *arr, int size);
void		sort_tre(t_list **stack);
void		print_stack(t_list *stack, int caso);
void		sort_five(t_list **stack_a, t_list **stack_b);
void		rev_indice_stack(t_list **stack, int *tmp);

#endif