/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:46:17 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/23 09:45:32 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_tre(stack_a);
	if (*stack_b && (*stack_b)->next && (*stack_b)->index > (*stack_b)->next->index)
		sb(stack_b);
	if (*stack_b && (*stack_b)->index == 0)
		pa(stack_a, stack_b);
	while (*stack_b && ((*stack_b)->index - (*stack_a)->index != 1))
		ra(stack_a);
	if (*stack_b && (*stack_b)->index - (*stack_a)->index == 1)
		ra(stack_a);
	if (*stack_b)
		pa(stack_a, stack_b);
	while (*stack_b && ((*stack_b)->index - (*stack_a)->index != 1))
		ra(stack_a);
	if (*stack_b && (*stack_b)->index - (*stack_a)->index == 1)
		ra(stack_a);
	if (*stack_b)
		pa(stack_a, stack_b);
	while ((*stack_a)->index != 0)
		ra(stack_a);
}

/*printf("PRE--------------------------------------\n");
print_stack(*stack_a, 1);
print_stack(*stack_b, 2);
printf("PRE--------------------------------------\n");*/