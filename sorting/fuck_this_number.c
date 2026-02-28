/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_this_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:19:52 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/28 15:58:01 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves(int rb, int ra, int lenA, int lenB)
{
	int	cost_a;
	int	cost_b;
	if (ra <= lenA / 2)
		cost_a = ra;
	else
		cost_a = lenA - ra;
	if (rb <= lenB / 2)
		cost_b = rb;
	else
		cost_b = lenB - rb;
	if ((ra <= lenA / 2 && rb <= lenB / 2) ||
		(ra > lenA / 2 && rb > lenB / 2))
	{
		return (cost_a > cost_b ? cost_a : cost_b);
	}
	else
	{
		return (cost_a + cost_b);
	}
}

int	max_index(t_list *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int find_pos(int index, t_list **stack_b)
{
	t_list *curr;
	int pos = 0;
	int best_pos = -1;
	int best_index = -2147483648;

	curr = *stack_b;
	if (!curr)
		return (0);
	while (curr)
	{
		if (curr->index < index && curr->index > best_index)
		{
			best_index = curr->index;
			best_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	if (best_pos != -1)
		return (best_pos);
	curr = *stack_b;
	pos = 0;
	best_index = -2147483648;
	best_pos = 0;
	while (curr)
	{
		if (curr->index > best_index)
		{
			best_index = curr->index;
			best_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (best_pos);
}

int	find_pos_in_a(int index, t_list **stack_a)
{
	t_list	*curr;
	int		pos;
	int		best_pos;
	int		best_index;
	int		min_pos;
	int		min_index;

	if (!*stack_a)
		return (0);
	curr = *stack_a;
	pos = 0;
	best_index = 2147483647;
	best_pos = -1;
	while (curr)
	{
		if (curr->index > index && curr->index < best_index)
		{
			best_index = curr->index;
			best_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	if (best_pos != -1)
		return (best_pos);
	curr = *stack_a;
	pos = 0;
	min_index = 2147483647;
	min_pos = 0;
	while (curr)
	{
		if (curr->index < min_index)
		{
			min_index = curr->index;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}
