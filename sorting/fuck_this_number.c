/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_this_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:19:52 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/25 09:40:24 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves(int rb, int ra, int lenA, int lenB)
{
	int	moves;

	if (ra == 0 || rb == 0)
		return (check_limit(ra, rb, lenA, lenB));
	if (rb < lenB / 2 && ra < lenA / 2)
	{
		if (rb < ra)
			moves = ra;
		else
			moves = rb;
	}
	if (rb > lenB / 2 && ra > lenA / 2)
	{
		if (rb < ra)
			moves = lenA - ra + 1;
		else
			moves = lenB - rb + 1;
	}
	if (rb > lenB / 2 && ra < lenA / 2)
		moves = ra + rb;
	if (rb < lenB / 2 && ra > lenA / 2)
		moves = ra + rb;
	return (moves);
}

int	check_limit(int rb, int ra, int lenA, int lenB)
{
	if (ra == 0 && rb < lenB / 2)
		return (rb);
	if (rb == 0 && ra < lenA / 2)
		return (ra);
	if (ra == 0 && rb > lenB / 2)
		return (lenB - rb + 1);
	else
		return (lenA - ra + 1);
}

int	is_min(t_list **stack_a, t_list **stack_b)
{
	t_list	*currA;
	t_list	*currB;

	currA = (*stack_a);
	currB = (*stack_b);
	while (currB != NULL)
	{
		if(currA->index > currB->index)
			return (0);
		currB = currB->next;
	}
	return(1);
}

int	is_max(t_list **stack_a, t_list **stack_b)
{
	t_list	*currA;
	t_list	*currB;

	currA = (*stack_a);
	currB = (*stack_b);
	while (currB != NULL)
	{
		if(currA->index < currB->index)
			return (0);
		currB = currB->next;
	}
	return(1);
}

int	find_pos(int index, t_list **stack_b)
{
	int		x;
	t_list	*currB;

	x = 0;
	currB = (*stack_b);
	while (currB->next != NULL)
	{
		if(index < currB->index && index > currB->next->index)
			break ;
		x++;
		currB = currB->next;
	}
	x++;
	return (x);
}
