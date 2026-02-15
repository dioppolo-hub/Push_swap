/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:36 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/15 21:02:41 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_double(t_list *stack_a, t_list *new)
{
	t_list	*corrente;
	int		numNew;

	numNew = *(int *)new->content;
	corrente = stack_a;
	while (corrente != NULL)
	{
		if (*(int *)corrente->content == numNew)
			ft_error();
		corrente = corrente->next;
	}
	return ;
}

static void	check_split(char *str)
{
	static int	i;

	i = 0;
	while (str[i])
	{
		if (!(((str[i] == '-' || str[i] == '+') || str[i] == ' ') || (str[i] >= '0' && str[i] <= '9')))
			ft_error();
		if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			ft_error();
		i++;
	}
	return ;
}

void	add_stack(char *argv, t_list **stack_a)
{
	int		x;
	char	**mat;
	int		tempnumb;
	t_list	*new;

	x = 0;
	mat = ft_split(argv, ' ');
	while (mat[x])
	{
		check_split(mat[x]);
		tempnumb = ft_atoi(mat[x]);
		new = ft_lstnew((int *)ft_calloc(1, sizeof(int)));
		*(int *)new->content = tempnumb;
		check_double(*stack_a, new);
		ft_lstadd_back(stack_a, new);
		x++;
	}
	ft_freemat(mat);
}
