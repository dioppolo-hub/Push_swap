/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_generico.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/ 20 21:57:30 by diego             #+#    #+#             */
/*   Updated: 2026/02/ 24 15:25:09 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int check_limit(int rb, int ra, int lenA, int lenB)
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



void	push_index(int c_ra, t_list **stack_a, t_list **stack_b)
{
	int		c_rb;
	int 	count;

	count = 0;
	if (c_ra < ft_lstsize(*stack_a) / 2)
	{
		c_rb = find_pos(c_ra, stack_b);
		if (c_rb < ft_lstsize(*stack_b) / 2)
		{
			if (c_ra < c_rb)
			{
				while (count < c_ra && ++count)
					rr(stack_a, stack_b);
				while (count < c_rb && ++count)
					rb(stack_b);
			}
			else
			{
				while (count < c_rb && ++count)
					rr(stack_a, stack_b);
				while (count < c_rb && ++count)
					ra(stack_a);
			}
		}
		else
		{
			while (count < c_ra && ++count)
				ra(stack_a);
			count = 0;
			while (count < ft_lstsize(*stack_b) - c_rb && ++count)
				rrb(stack_b);
		}
	}
	else
	{
		c_rb = find_pos(c_ra, stack_b);
		if (c_rb < ft_lstsize(*stack_b) / 2)
		{
			if (c_ra < c_rb)
			{
				while (count < ft_lstsize(*stack_b) - c_rb && ++count)
					rrr(stack_a, stack_b);
				while (count < ft_lstsize(*stack_a) - c_ra && ++count)
					rrb(stack_b);
			}
			else
			{
				while (count < ft_lstsize(*stack_a) - c_ra && ++count)
					rrr(stack_a, stack_b);
				while (count < ft_lstsize(*stack_b) - c_rb && ++count)
					rra(stack_a);
			}
		}
		else
		{
			while (count < ft_lstsize(*stack_a) - c_ra && ++count)
				rra(stack_a);
			count = 0;
			while (count < c_rb && ++count)
				rb(stack_b);
		}
	}
	pb(stack_a, stack_b);
}

void	push_middle(t_list **stack_a, t_list **stack_b, int ra)
{
	int		moves;
	int		min_move;
	int		pos;
	t_list	*currA;
	int		index_to_push;

	ra = 0;
	min_move = -1;
	currA = (*stack_a);
	while (currA != NULL)
	{
		pos = find_pos(currA->index, stack_b);
		moves = calc_moves(pos, ra, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		if (moves > min_move || min_move == -1)
		{
			index_to_push = currA->index;
			min_move = moves;
		}
		currA = currA->next;
		ra++;
	}
	push_index(index_to_push, stack_a, stack_b);
}

static void	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	while ((*stack_a) != NULL)
	{
		if (is_max(stack_a, stack_b) == 1)
			pb(stack_a, stack_b);
		else if (is_min(stack_a, stack_b) == 1)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			push_middle(stack_a, stack_b, 0);
	}
}

/* static void	sort_to_a(t_list **stack_a, t_list **stack_b)
{
	
} */

void	sort_generico(t_list **stack_a, t_list **stack_b)
{
	sort_to_b(stack_a, stack_b);
	//sort_to_a(stack_a, stack_b);
}
