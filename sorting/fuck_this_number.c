/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_this_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:19:52 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/04 13:37:17 by diego            ###   ########.fr       */
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

int	pos_min(t_list	**stack_a)
{
	int		min;
	int		i;
	t_list	*curr;

	min = 0;
	i = 0;
	curr = (*stack_a);
	while (curr)
	{
		if (curr->index == min)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}
