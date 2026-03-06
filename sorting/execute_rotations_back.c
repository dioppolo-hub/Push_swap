/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotations_back.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:00 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/06 11:10:57 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_up(t_list **a, t_list **b, int rb_pos, int ra_pos)
{
	int	common;
	int	ra_moves;
	int	rb_moves;

	common = min(ra_pos, rb_pos);
	ra_moves = ra_pos - common;
	rb_moves = rb_pos - common;
	while (common--)
		rr(a, b, 1);
	while (ra_moves--)
		ra(a, 1);
	while (rb_moves--)
		rb(b, 1);
}

static void	both_down(t_list **a, t_list **b, int rb_pos, int ra_pos)
{
	int	common;
	int	ra_moves;
	int	rb_moves;

	ra_moves = ft_lstsize(*a) - ra_pos;
	rb_moves = ft_lstsize(*b) - rb_pos;
	common = min(ra_moves, rb_moves);
	ra_moves -= common;
	rb_moves -= common;
	while (common--)
		rrr(a, b, 1);
	while (ra_moves--)
		rra(a, 1);
	while (rb_moves--)
		rrb(b, 1);
}

static void	up_down(t_list **a, t_list **b, int rb_pos, int ra_pos)
{
	int	ra_moves;
	int	rb_moves;

	ra_moves = ra_pos;
	rb_moves = ft_lstsize(*b) - rb_pos;
	while (ra_moves--)
		ra(a, 1);
	while (rb_moves--)
		rrb(b, 1);
}

static void	down_up(t_list **a, t_list **b, int rb_pos, int ra_pos)
{
	int	ra_moves;
	int	rb_moves;

	ra_moves = ft_lstsize(*a) - ra_pos;
	rb_moves = rb_pos;
	while (ra_moves--)
		rra(a, 1);
	while (rb_moves--)
		rb(b, 1);
}

void	execute_rotations_back(int rb_pos, t_list **a, t_list **b)
{
	int		ra_pos;
	t_list	*tmp;
	int		i;

	tmp = *b;
	i = 0;
	while (i < rb_pos)
	{
		tmp = tmp->next;
		i++;
	}
	ra_pos = find_pos_in_a(tmp->index, a);
	if (ra_pos < ft_lstsize(*a) / 2 && rb_pos < ft_lstsize(*b) / 2)
		both_up(a, b, rb_pos, ra_pos);
	else if (ra_pos >= ft_lstsize(*a) / 2 && rb_pos >= ft_lstsize(*b) / 2)
		both_down(a, b, rb_pos, ra_pos);
	else if (ra_pos < ft_lstsize(*a) / 2 && rb_pos >= ft_lstsize(*b) / 2)
		up_down(a, b, rb_pos, ra_pos);
	else
		down_up(a, b, rb_pos, ra_pos);
	pa(a, b, 1);
}
