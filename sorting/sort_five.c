/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:46:17 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/20 19:28:01 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_tre(stack_a);
	if (*stack_b && (*stack_b)->next && (*stack_b)->content > (*stack_b)->next->content)
		sb(stack_b);
	if (*stack_b && (*stack_b)->content == 0)
		pa(stack_a, stack_b);
	while (*stack_b && ((*stack_b)->content - (*stack_a)->content != 1))
		ra(stack_a);
	if (*stack_b && (*stack_b)->content - (*stack_a)->content == 1)
		ra(stack_a);
	if (*stack_b)
		pa(stack_a, stack_b);
	while (*stack_b && ((*stack_b)->content - (*stack_a)->content != 1))
		ra(stack_a);
	if (*stack_b && (*stack_b)->content - (*stack_a)->content == 1)
		ra(stack_a);
	if (*stack_b)
		pa(stack_a, stack_b);
	while ((*stack_a)->content != 0)
		ra(stack_a);
}

/*printf("PRE--------------------------------------\n");
print_stack(*stack_a, 1);
print_stack(*stack_b, 2);
printf("PRE--------------------------------------\n");*/