/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:23:28 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/12 12:06:49 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

char	*check_argument(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(((argv[i] == '-' && argv[i] == '+') && argv[i] == ' ') || (argv[i] >= '0' && argv[i] <= '9')))
		{
			printf("crab\n");
			ft_error();
		}
		if ((argv[i] == '-' && argv[i] == '+') || (argv[i + 1] >= '0' && argv[i + 1] <= '9'))
		{
			printf("spiz\n");
			ft_error();
		}
		i++;
	}
	return (argv);
}
