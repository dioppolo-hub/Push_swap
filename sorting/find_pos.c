/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:22:15 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/02 10:38:29 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_norm(t_list **stack_b)
{
	t_list	*curr;
	int		pos;
	int		best_pos;
	int		best_index;

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

int	find_pos(int index, t_list **stack_b)
{
	t_list	*curr;
	int		pos;
	int		best_pos;
	int		best_index;

	pos = 0;
	best_pos = -1;
	best_index = -2147483648;
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
	return (find_pos_norm(stack_b));
}

int	norm_find_pos_a(t_list *curr, int best_index, int index)
{
	int	best_pos;
	int	pos;

	best_pos = -1;
	pos = 0;
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
	return (best_pos);
}

int	norm_find_pos_a2(t_list *curr, int min_index)
{
	int	pos;
	int	min_pos;

	pos = 0;
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

int	find_pos_in_a(int index, t_list **stack_a)
{
	t_list	*curr;
	int		best_pos;
	int		best_index;
	int		min_pos;
	int		min_index;

	if (!*stack_a)
		return (0);
	curr = *stack_a;
	best_index = 2147483647;
	best_pos = norm_find_pos_a(curr, best_index, index);
	if (best_pos != -1)
		return (best_pos);
	curr = *stack_a;
	min_index = 2147483647;
	min_pos = norm_find_pos_a2(curr, min_index);
	return (min_pos);
}
