/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:22:47 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/16 17:53:16 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack_a)
{
	t_list	*a;
	t_list	*b;
	
	if (!(*stack_a && (*stack_a)->next))
		return ;
	a = (*stack_a);
	b = a->next;
	a->next = b->next;
	b->next = a;
	(*stack_a) = b;
}

int	sa(t_list **stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
	return (1);
}

int	sb(t_list **stack_b)
{
	swap(stack_b);
	write (1, "sb\n", 3);
	return (1);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
	return (1);
}