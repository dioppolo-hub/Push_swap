/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:56:59 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/19 09:16:59 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*corrente;

	corrente = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (corrente->next != NULL)
		corrente = corrente->next;
	corrente->next = new;
}
