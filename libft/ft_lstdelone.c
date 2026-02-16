/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:42:57 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/16 17:27:46 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}
/*
void	printlist(t_list *p)
{
	if(p == NULL)
		return;
	while (p != NULL)
	{
		if (p->next != NULL)
			printf("[%s]->", (char *)p->content);
		else
			printf("[%s]", (char *)p->content);
		p = p->next;
	}
	printf("\n");
}
int		main()
{
	t_list *nodo;
	char *str;

	str = (char *)malloc(sizeof(char) * 6);
	if (!str)
		return (0);
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';
	nodo = (t_list *)malloc(sizeof(t_list));
	if (!nodo)
		return (0);
	nodo->content = str;
	nodo->next = NULL;
	printf("prima:\n");
	printlist(nodo);
	ft_lstdelone(nodo, del);
	printf("dopo:\n");
	printlist(nodo);
} */