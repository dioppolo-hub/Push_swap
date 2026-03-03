/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:46:17 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/03 13:45:54 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_list *stack, int target)
{
	int	x;

	x = 0;
	while (stack && (stack)->index != target)
	{
		x++;
		(stack) = (stack)->next;
	}
	return (x);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b);
	sort_tre(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/*printf("PRE--------------------------------------\n");
print_stack(*stack_a, 1);
print_stack(*stack_b, 2);
printf("PRE--------------------------------------\n");*/