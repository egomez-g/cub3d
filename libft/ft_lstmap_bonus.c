/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:35:28 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/09/28 09:35:30 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	p = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (new == NULL)
		{
			del(content);
			ft_lstclear(&p, *del);
			return (NULL);
		}
		ft_lstadd_back(&p, new);
		lst = lst->next;
	}
	return (p);
}
