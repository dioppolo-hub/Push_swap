/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:01:21 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/03 16:15:18 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_up(t_list **stack_a, t_list **stack_b, int c_ra, int c_rb)
{
	int	common;
	int	rb_moves;
	int	ra_moves;

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

void	both_down(t_list **stack_a, t_list **stack_b, int c_ra, int c_rb)
{
	int	rr_a;
	int	rr_b;
	int	common;
	int	ra_moves;
	int	rb_moves;

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

void	down_up(t_list **stack_a, t_list **stack_b, int c_ra, int c_rb)
{
	int	ra_moves;
	int	rb_moves;

	ra_moves = c_ra;
	rb_moves = ft_lstsize(*stack_b) - c_rb;
	while (ra_moves > 0 && ra_moves--)
		ra(stack_a);
	while (rb_moves > 0 && rb_moves--)
		rrb(stack_b);
}

void	up_down(t_list **stack_a, t_list **stack_b, int c_ra, int c_rb)
{
	int	ra_moves;
	int	rb_moves;

	ra_moves = ft_lstsize(*stack_a) - c_ra;
	rb_moves = c_rb;
	while (ra_moves > 0 && ra_moves--)
		rra(stack_a);
	while (rb_moves > 0 && rb_moves--)
		rb(stack_b);
}

void	push_index(int c_ra, t_list **a, t_list **b)
{
	int		c_rb;
	t_list	*tmp;
	int		i;
	int		index;

	i = 0;
	tmp = *a;
	while (i < c_ra)
	{
		tmp = tmp->next;
		i++;
	}
	index = tmp->index;
	c_rb = find_pos(index, b);
	if (c_ra < ft_lstsize(*a) / 2 && c_rb < ft_lstsize(*b) / 2)
		both_up(a, b, c_ra, c_rb);
	else if (c_ra >= ft_lstsize(*a) / 2 && c_rb >= ft_lstsize(*b) / 2)
		both_down(a, b, c_ra, c_rb);
	else if (c_ra < ft_lstsize(*a) / 2 && c_rb >= ft_lstsize(*b) / 2)
		down_up(a, b, c_ra, c_rb);
	else if (c_ra >= ft_lstsize(*a) / 2 && c_rb < ft_lstsize(*b) / 2)
		up_down(a, b, c_ra, c_rb);
	pb(a, b);
}
