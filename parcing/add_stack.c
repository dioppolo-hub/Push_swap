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

static void	ft_freemat(char **mat)
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
static void	check_split(char **mat)
{
	static int	i;
	int			j;

	i = 0;
	j = 0;
	while (mat[i])
	{
		if (!(((mat[i][j] == '-' && mat[i][j] == '+') && mat[i][j] == ' ') || (mat[i][j] >= '0' && mat[i][j] <= '9')))
		{
			printf("crab\n");
			ft_error();
		}
		if ((mat[i][j] == '-' && mat[i][j] == '+') || (mat[i][j + 1] >= '0' && mat[i][j + 1] <= '9'))
		{
			printf("spiz\n");
			ft_error();
		}
		j++;
	}
	i++;
	return ;
}

void	add_stack(char *argv, t_list **stack_a)
{
	int		x;
	char	**mat;
	int		tempnumb;
	t_list	*new;

	x = 0;
	mat = ft_split(argv, ' ');
	while (mat[x])
	{
		check_split(mat);
		tempnumb = ft_atoi(mat[x]);
		new = ft_lstnew((int *)ft_calloc(1, sizeof(int)));
		*(int *)new->content = tempnumb;
		ft_lstadd_back(stack_a, new);
		x++;
	}
	ft_freemat(mat);
}
