/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:36 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/12 12:37:23 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_freeall(char *str)
{
	
}

int	add_stack(char *argv, t_list **stack_a)
{
	int		x;
	char	**mat;
	int		tempnumb;
	t_list	*new;

	x = 0;
	mat = ft_split(argv, " ");
	while (mat[x])
	{
		tempnumb = ft_atoi(mat[x]);
		new = ft_lstnew(tempnumb);
		ft_lstadd_back(stack_a, new);
		x++;
	}
}
