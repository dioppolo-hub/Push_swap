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

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	push_index(int c_ra, t_list **stack_a, t_list **stack_b)
{
	int		c_rb;
	int		common;
	int		ra_moves;
	int		rb_moves;
	int		rr_b;
	int		rr_a;
	t_list *tmp;
	int i;
	int index;

	i = 0;
	tmp = *stack_a;
	while (i < c_ra)
	{
		tmp = tmp->next;
		i++;
	}
	index = tmp->index;
	c_rb = find_pos(index, stack_b);
	if (c_ra < ft_lstsize(*stack_a) / 2 && c_rb < ft_lstsize(*stack_b) / 2)
	{
		common = min(c_ra, c_rb);
		ra_moves = c_ra - common;
		rb_moves = c_rb - common;
		while (common > 0 && common--)
			rr(stack_a, stack_b);
		while (ra_moves > 0 && ra_moves--)
			ra(stack_a);
		while (rb_moves > 0 && rb_moves--)
			rb(stack_b);
	}
	else if (c_ra >= ft_lstsize(*stack_a) / 2 && c_rb >= ft_lstsize(*stack_b) / 2)
	{
		rr_a = ft_lstsize(*stack_a) - c_ra;
		rr_b = ft_lstsize(*stack_b) - c_rb;
		common = min(rr_a, rr_b);
		ra_moves = rr_a - common;
		rb_moves = rr_b - common;
		while (common > 0 && common--)
			rrr(stack_a, stack_b);
		while (ra_moves > 0 && ra_moves--)
			rra(stack_a);
		while (rb_moves > 0 && rb_moves--)
			rrb(stack_b);
	}
	else if (c_ra < ft_lstsize(*stack_a) / 2 && c_rb >= ft_lstsize(*stack_b) / 2)
	{
		ra_moves = c_ra;
		rb_moves = ft_lstsize(*stack_b) - c_rb;
		while (ra_moves > 0 && ra_moves--)
			ra(stack_a);
		while (rb_moves > 0 && rb_moves--)
			rrb(stack_b);
	}
	else if (c_ra >= ft_lstsize(*stack_a) / 2 && c_rb < ft_lstsize(*stack_b) / 2)
	{
		ra_moves = ft_lstsize(*stack_a) - c_ra;
		rb_moves = c_rb;
		while (ra_moves > 0 && ra_moves--)
			rra(stack_a);
		while (rb_moves > 0 && rb_moves--)
			rb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	push_middle(t_list **stack_a, t_list **stack_b, int ra)
{
	int		moves;
	int		min_move;
	int		pos;
	t_list	*currA;
	int		best_ra;

	ra = 0;
	min_move = -1;
	currA = (*stack_a);
	while (currA != NULL)
	{
		pos = find_pos(currA->index, stack_b);
		moves = calc_moves(pos, ra, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		if (moves < min_move || min_move == -1)
		{
			best_ra = ra;
			min_move = moves;
		}
		currA = currA->next;
		ra++;
	}
	push_index(best_ra, stack_a, stack_b);
}

void	execute_rotations_back(int rb_pos, t_list **a, t_list **b)
{
	int	ra_pos;
	int	common;
	int	ra_moves;
	int	rb_moves;
	t_list	*tmp;
	int	i;

	tmp = *b;
	i = 0;
	while (i < rb_pos)
	{
		tmp = tmp->next;
		i++;
	}
	ra_pos = find_pos_in_a(tmp->index, a);
	if (ra_pos < ft_lstsize(*a) / 2 && rb_pos < ft_lstsize(*b) / 2)
	{
		common = min(ra_pos, rb_pos);
		ra_moves = ra_pos - common;
		rb_moves = rb_pos - common;
		while (common--)
			rr(a, b);
		while (ra_moves--)
			ra(a);
		while (rb_moves--)
			rb(b);
	}
	else if (ra_pos >= ft_lstsize(*a) / 2 && rb_pos >= ft_lstsize(*b) / 2)
	{
		ra_moves = ft_lstsize(*a) - ra_pos;
		rb_moves = ft_lstsize(*b) - rb_pos;
		common = min(ra_moves, rb_moves);
		ra_moves -= common;
		rb_moves -= common;
		while (common--)
			rrr(a, b);
		while (ra_moves--)
			rra(a);
		while (rb_moves--)
			rrb(b);
	}
	else if (ra_pos < ft_lstsize(*a) / 2 && rb_pos >= ft_lstsize(*b) / 2)
	{
		ra_moves = ra_pos;
		rb_moves = ft_lstsize(*b) - rb_pos;
		while (ra_moves--)
			ra(a);
		while (rb_moves--)
			rrb(b);
	}
	else
	{
		ra_moves = ft_lstsize(*a) - ra_pos;
		rb_moves = rb_pos;
		while (ra_moves--)
			rra(a);
		while (rb_moves--)
			rb(b);
	}
	pa(a, b);
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	int		rb;
	int		pos;
	int		moves;
	int		best_rb;
	int		min_move;
	t_list	*currB;

	min_move = -1;
	rb = 0;
	currB = *stack_b;
	while (currB)
	{
		pos = find_pos_in_a(currB->index, stack_a);
		moves = calc_moves(rb, pos, ft_lstsize(*stack_a), ft_lstsize(*stack_b));

		if (moves < min_move || min_move == -1)
		{
			min_move = moves;
			best_rb = rb;
		}
		currB = currB->next;
		rb++;
	}
	execute_rotations_back(best_rb, stack_a, stack_b);
}

static void	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	while (ft_lstsize(*stack_a) > 3)
		push_middle(stack_a, stack_b, 0);
	sort_tre(stack_a);
}

void	sort_generico(t_list **stack_a, t_list **stack_b)
{
	sort_to_b(stack_a, stack_b);
	while (*stack_b)
		push_back(stack_a, stack_b);
	while ((*stack_a)->index != 0)
		ra(stack_a);
}
