/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:09:28 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/03 13:54:43 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
/* void	printlist(t_list *p)
{
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
void	del(void *content)
{
	free(content);
}
int	main()
{
	t_list *testa = NULL;

	char *str1 = ft_strdup("Hello");
	char *str2 = ft_strdup("World");
	char *str3 = ft_strdup("Everyone");

	ft_lstadd_back(&testa, ft_lstnew(str1));
	ft_lstadd_back(&testa, ft_lstnew(str2));
	ft_lstadd_back(&testa, ft_lstnew(str3));

	printf("prima:\n");
	printlist(testa);
	ft_lstclear(&testa, del);
	printf("dopo:\n");
	printlist(testa);
} */