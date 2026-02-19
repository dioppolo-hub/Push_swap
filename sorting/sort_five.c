/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:46:17 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/19 16:46:26 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	// t_list	*curr;

	// curr = (*stack_a);
	// while (curr && curr->next && curr->content < curr->next->content)
	// 	curr = curr->next;
	// if (curr->next == NULL)
	// 	return ;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_tre(stack_a);
	if ((*stack_b)->content > (*stack_b)->next->content)
		sb(stack_b);
	if ((*stack_b)->content == 0)
		pa(stack_a, stack_b);
	while ((*stack_b)->content - (*stack_a)->content != 1)
		ra(stack_a);
	if ((*stack_b)->content - (*stack_a)->content == 1)
		ra(stack_a);
	pa(stack_a, stack_b);
	while ((*stack_b)->content - (*stack_a)->content != 1)
		ra(stack_a);
	if ((*stack_b)->content - (*stack_a)->content == 1)
		ra(stack_a);
	pa(stack_a, stack_b);
	while ((*stack_a)->content != 0)
		ra(stack_a);
}
