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

int	min(int c_ra, int c_rb)
{
	int	common;

	common = 0;
	if (c_ra == c_rb)
		common = c_rb = c_ra;
	if (c_ra > c_rb)
		common = c_rb;
	else
		common = c_ra;
	return (common);
}

void	push_index(int c_ra, t_list **stack_a, t_list **stack_b)
{
	int		c_rb;
	int		common;
	int		ra_moves;
	int		rb_moves;

	if (c_ra < ft_lstsize(*stack_a) / 2)
	{
		c_rb = find_pos(c_ra, stack_b);
		common = min(c_ra, c_rb);
		ra_moves = c_ra - common;
		rb_moves = c_rb - common;
		if (c_rb < ft_lstsize(*stack_b) / 2)
		{
			if (c_ra < c_rb)
			{
				while (common < c_ra && common--)
					rr(stack_a, stack_b);
				while (rb_moves < c_rb && rb_moves--)
					rb(stack_b);
			}
			else
			{
				while (common < c_rb && common--)
					rr(stack_a, stack_b);
				while (rb_moves < c_rb && rb_moves--)
					ra(stack_a);
			}
		}
		else
		{
			while (ra_moves < c_ra && ra_moves--)
				ra(stack_a);
			while (rb_moves < ft_lstsize(*stack_b) - c_rb && rb_moves--)
				rrb(stack_b);
		}
	}
	else
	{
		c_rb = find_pos(c_ra, stack_b);
		common = min(c_ra, c_rb);
		ra_moves = c_ra - common;
		rb_moves = c_rb - common;
		if (c_rb < ft_lstsize(*stack_b) / 2)
		{
			if (c_ra < c_rb)
			{
				while (common < ft_lstsize(*stack_b) - c_rb && common--)
					rrr(stack_a, stack_b);
				while (rb_moves < ft_lstsize(*stack_a) - c_ra && rb_moves--)
					rrb(stack_b);
			}
			else
			{
				while (common < ft_lstsize(*stack_a) - c_ra && common--)
					rrr(stack_a, stack_b);
				while (ra_moves < ft_lstsize(*stack_b) - c_rb && ra_moves--)
					rra(stack_a);
			}
		}
		else
		{
			while (ra_moves < ft_lstsize(*stack_a) - c_ra && ra_moves--)
				rra(stack_a);
			while (rb_moves < c_rb && rb_moves--)
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



void	sort_generico(t_list **stack_a, t_list **stack_b)
{
	sort_to_b(stack_a, stack_b);
	//sort_to_a(stack_a, stack_b);
}
