/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:56:05 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/23 14:05:32 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	print_stack(*stack, 1);
	if (!(*stack && (*stack)->next))
		return ;
	first = (*stack);
	second = (first)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	(*stack) = second;
}

int	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (1);
}
