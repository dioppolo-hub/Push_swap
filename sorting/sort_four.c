/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:28:20 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/23 14:30:21 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	x;

	x = find_index(*stack_a, 0);
	while (x--)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_tre(stack_a);
	pa(stack_a, stack_b);
}