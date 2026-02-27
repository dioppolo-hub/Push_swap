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

static void	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	while ((*stack_a) != NULL)
			push_middle(stack_a, stack_b, 0);
}

void	sort_generico(t_list **stack_a, t_list **stack_b)
{
	sort_to_b(stack_a, stack_b);
	while ((*stack_b)->index != max(stack_a))
		rb(stack_b);
	rb(stack_b);
	rb(stack_b);
	while ((*stack_b))
		pa(stack_a, stack_b);
}
