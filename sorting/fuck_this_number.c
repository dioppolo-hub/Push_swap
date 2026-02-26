/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_this_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:19:52 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/26 11:49:29 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves(int rb, int ra, int lenA, int lenB)
{
	int	moves;

	moves = 0;
	if (ra == 0 || rb == 0)
		return (check_limit(rb, ra, lenA, lenB));
	if (rb <= lenB / 2 && ra <= lenA / 2)
	{
		if (ra > rb)
			moves = ra;
		else
			moves = rb;
	}
	else if (rb > lenB / 2 && ra > lenA / 2)
	{
		if ((lenB - rb) > (lenA - ra))
			moves = lenB - rb;
		else
			moves = lenA - ra;
	}
	else if (rb > lenB / 2 && ra < lenA / 2)
		moves = ra + (lenB - rb);
	else
		moves = (lenA - ra) + rb;
	return (moves);
}

int	check_limit(int rb, int ra, int lenA, int lenB)
{
	if (ra == 0)
	{
		if (rb <= lenB / 2)
			return (rb);
		else
			return (lenB - rb);
	}
	else
	{
		if (ra <= lenA / 2)
			return (ra);
		else
			return (lenA - ra);
	}
}

int	is_min(int index, t_list **stack_b)
{
	t_list	*currB;

	if ((*stack_b) == NULL)
		return (1);
	currB = (*stack_b);
	while (currB != NULL)
	{
		if(index > currB->index)
			return (0);
		currB = currB->next;
	}
	return(1);
}

int	is_max(int index, t_list **stack_b)
{
	t_list	*currB;

	if ((*stack_b) == NULL)
		return (1);
	currB = (*stack_b);
	while (currB != NULL)
	{
		if(index < currB->index)
			return (0);
		currB = currB->next;
	}
	return(1);
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
		return (best_pos + 1);
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
	return (best_pos + 1);
}
