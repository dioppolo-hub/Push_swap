/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:02:29 by diego             #+#    #+#             */
/*   Updated: 2026/03/03 14:25:45 by dioppolo         ###   ########.fr       */
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
