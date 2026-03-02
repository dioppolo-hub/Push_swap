/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_this_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:19:52 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/02 09:59:16 by dioppolo         ###   ########.fr       */
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
	if ((ra <= lenA / 2 && rb <= lenB / 2)
		|| (ra > lenA / 2 && rb > lenB / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
		return (cost_a + cost_b);
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
