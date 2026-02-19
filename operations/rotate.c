/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:56:05 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/19 09:18:32 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack && (*stack)->next))
		return ;
	first = (*stack);
	(*stack) = first->next;
	last = (*stack);
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
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
