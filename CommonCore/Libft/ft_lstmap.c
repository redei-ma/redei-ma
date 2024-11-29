/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:24:10 by redei-ma          #+#    #+#             */
/*   Updated: 2024/11/27 14:28:54 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst -> next;
	}
	return (new);
}

/* void ft_deletecont(void *content)
{
	free(content);
}

void	*ft_lstchange(void *content)
{
	return(content += 1);
}

int main()
{
	t_list	*node = ft_lstnew(ft_strdup("voglio andare a casa"));
	node -> next = ft_lstnew(ft_strdup("go home"));
	
	t_list *head = node;
	while(node)
	{
		printf("%s\n", (char *)node ->content);
		node = node -> next;
	}
	head = ft_lstmap(head, ft_lstchange, ft_deletecont);
	while(head)
	{
		printf("%s\n", (char *)head ->content);
		head = head -> next;
	}
} */