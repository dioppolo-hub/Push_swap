/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:09:41 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/23 09:45:46 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tre(t_list **stack)
{
	t_list	*curr;
	t_list	*middle;
	t_list	*last;

	curr = (*stack);
	middle = (*stack)->next;
	last = (*stack)->next->next;
	if ((curr->index > middle->index) && (curr->index < last->index))
		sa(stack);
	if ((curr->index > middle->index) && (curr->index > last->index))
	{
		ra(stack);
		if (middle->index > last->index)
			sa(stack);
	}
	if ((curr->index < middle->index)
		&& (curr->index > last->index))
		rra(stack);	
	if ((curr->index < middle->index) && (middle->index > last->index)
		&& (curr->index < last->index))
	{
		rra(stack);
		sa(stack);
	}
}
