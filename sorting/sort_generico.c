/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_generico.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:57:30 by diego             #+#    #+#             */
/*   Updated: 2026/02/22 18:27:41 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	int	media;
	int	chunk_size;
	int	i;

	chunk_size = 20;
	media = chunk_size / 2;
	i = 0;
	while ((*stack_a) != NULL && i < chunk_size)
	{
		if (i == chunk_size - 1)
		{
			chunk_size = chunk_size + 20;
			media = chunk_size / 2;
		}
		if ((*stack_a) && (*stack_a)->content > chunk_size)
			ra(stack_a);
		else if ((*stack_a) && (*stack_a)->content <= chunk_size)
		{
			i = i + pb(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->content < media)
				rb(stack_b);
		}
	}
}

static void	sort_to_a(t_list **stack_a, t_list **stack_b)
{
	
}

void	sort_generico(t_list **stack_a, t_list **stack_b)
{
	sort_to_b(&stack_a, &stack_b);
	sort_to_a(&stack_a, &stack_b);
}
