/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_generico.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:57:30 by diego             #+#    #+#             */
/*   Updated: 2026/02/20 22:54:30 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_generico(t_list **stack_a, t_list **stack_b)
{
	int	media;
	int	chunk_size;
	int	i;

	chunk_size = 20;
	media = chunk_size / 2;
	i = 0;
	while((*stack_a)->next != NULL && i <= chunk_size)
	{
		if(i < chunk_size)
			chunk_size = chunk_size + 20;
		if((*stack_a) && (*stack_a)->content > chunk_size)
			ra(stack_a);
		if((*stack_a) && (*stack_a)->content < chunk_size)
		{
			i = i + pb(stack_a, stack_b);
			if((*stack_a)->content < media && (*stack_b) && (*stack_b)->next)
				rb(stack_b);
		}
	}
}
