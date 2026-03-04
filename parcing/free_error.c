/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:02:29 by diego             #+#    #+#             */
/*   Updated: 2026/03/04 17:50:05 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	free_all(t_list **stack_a, char **mat)
{
	ft_lstclear(stack_a);
	ft_freemat(mat);
	ft_error();
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

void	ft_freemat(char **mat)
{
	int	x;

	x = 0;
	while (mat[x])
	{
		free(mat[x]);
		x++;
	}
	free(mat);
}
