/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:36 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/16 16:30:16 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_double(t_list *stack_a, t_list *new)
{
	t_list	*corrente;
	int		num;

	num = (int)new->content;
	corrente = stack_a;
	while (corrente != NULL)
	{
		if ((int)corrente->content == num)
			ft_error();
		corrente = corrente->next;
	}
	return ;
}

int	check_split(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(((str[i] == '-' || str[i] == '+') || str[i] == ' ') || (str[i] >= '0' && str[i] <= '9')))
			ft_error();
		if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			ft_error();
		i++;
	}
	return (1);
}

void	add_stack(char *argv, t_list **stack_a)
{
	int		x;
	char	**mat;
	int		n;
	t_list	*new;

	x = 0;
	mat = ft_split(argv, ' ');
	while (mat[x])
	{
		check_split(mat[x]);
		n = ft_atoi(mat[x]);
		new = ft_lstnew(n);
		check_double(*stack_a, new);
		ft_lstadd_back(stack_a, new);
		x++;
	}
	ft_freemat(mat);
}
