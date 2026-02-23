/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:46:17 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/23 14:22:08 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index(t_list *stack, int target)
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
	int	x;

	x = find_index(*stack_a, 0);
	while (x != 0)
	{
		ra(stack_a);
		x--;
	}
	pb(stack_a, stack_b);
	x = find_index(*stack_a, 1);
	while (x != 0)
	{
		ra(stack_a);
		x--;
	}
	pb(stack_a, stack_b);
	sort_tre(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/*printf("PRE--------------------------------------\n");
print_stack(*stack_a, 1);
print_stack(*stack_b, 2);
printf("PRE--------------------------------------\n");*/