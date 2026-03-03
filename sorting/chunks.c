/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:06:49 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/03 16:12:17 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back(t_list **stack_a, t_list **stack_b, int rb)
{
	int		pos;
	int		moves;
	int		best_rb;
	int		min_move;
	t_list	*curr;

	min_move = -1;
	curr = *stack_b;
	while (curr)
	{
		pos = find_pos_in_a(curr->index, stack_a);
		moves = calc_moves(rb, pos, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		if (moves < min_move || min_move == -1)
		{
			min_move = moves;
			best_rb = rb;
		}
		curr = curr->next;
		rb++;
	}
	execute_rotations_back(best_rb, stack_a, stack_b);
}

static void	norm_chunks(t_list **stack_a, t_list **stack_b)
{
	int	counter;
	int	chunk_size;
	int	temp;

	counter = 2;
	chunk_size = ft_lstsize(*stack_a) / 10;
	temp = 1;
	while (ft_lstsize(*stack_a) > 0)
	{
		if (ft_lstsize(*stack_b) == counter * chunk_size)
		{
			temp = counter + 1;
			counter += 2;
		}
		if ((*stack_a)->index < chunk_size * temp)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if ((*stack_a)->index < chunk_size * counter)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void	chunks(t_list **stack_a, t_list **stack_b, int size)
{
	if (size <= 100)
	{
		sort_generico(stack_a, stack_b);
		return ;
	}
	norm_chunks(stack_a, stack_b);
	while (*stack_b)
		push_back(stack_a, stack_b, 0);
	if (pos_min(stack_a) < ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->index != 0)
			ra(stack_a);
	else
		while ((*stack_a)->index != 0)
			rra(stack_a);
}
