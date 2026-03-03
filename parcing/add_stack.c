/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:36 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/03 14:23:11 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_double(t_list *stack_a, int num)
{
	t_list	*corrente;

	corrente = stack_a;
	while (corrente != NULL)
	{
		if ((int)corrente->content == num)
			return (0);
		corrente = corrente->next;
	}
	return (1);
}

int	check_split(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(((str[i] == '-' || str[i] == '+')
					|| str[i] == ' ')
				|| (str[i] >= '0' && str[i] <= '9')))
			return (0);
		if ((str[i] == '-' || str[i] == '+')
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	add_stack(char *argv, t_list **stack_a)
{
	int			x;
	char		**mat;
	long int	n;
	t_list		*new;

	x = 0;
	mat = ft_split(argv, ' ');
	while (mat[x])
	{
		if (!check_split(mat[x]))
			free_all(stack_a, mat);
		n = ft_atoi(mat[x]);
		if (n > INT_MAX || n < INT_MIN)
			free_all(stack_a, mat);
		if (!check_double(*stack_a, n))
			free_all(stack_a, mat);
		new = ft_lstnew(n);
		ft_lstadd_back(stack_a, new);
		x++;
	}
	ft_freemat(mat);
}
