/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:36:43 by diego             #+#    #+#             */
/*   Updated: 2026/03/06 11:01:00 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*norm_read(char *line, int i, int r)
{
	char	buffer;

	while (1)
	{
		r = read(0, &buffer, 1);
		if (r <= 0)
		{
			if(i == 0)
			{
				free(line);
				return (NULL);
			}
			break ;
		}
		if (buffer == '\n')
			break ;
		if (i >= 4)
		{
			write(2, "Error\n", 6);
			free(line);
			return (NULL);
		}
		line[i++] = buffer;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(void)
{
	char	*line;
	int		i;
	int		r;

	i = 0;
	r = 1;
	line = ft_calloc(5, sizeof(char));
	if (!line)
		return (NULL);
	return (norm_read(line, i, r));
}

int	execute_instruction(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b, 0);
	else if (!ft_strcmp(line, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	norm_main(t_list **a, t_list **b)
{
	char	*line;

	while (1)
	{
		line = read_line();
		if (!line)
			break ;
		if (!execute_instruction(line, a, b))
		{
			write(2, "Error\n", 6);
			free(line);
			free_stacks(a, b);
			exit(1);
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		x;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	x = 1;
	while (x < argc)
		add_stack(argv[x++], &a);
	norm_main(&a, &b);
	indice_stack(&a, ft_lstsize(a));
	if (!is_already_sort(&a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&a, &b);
	return (0);
}
