/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:28:20 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/06 11:11:38 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	x;

	x = find_index(*stack_a, 0);
	while (x--)
		ra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_tre(stack_a);
	pa(stack_a, stack_b, 1);
}
