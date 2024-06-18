/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:35:06 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/09/28 09:35:08 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*q;

	p = *lst;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		ft_lstdelone(q, del);
		q = NULL;
	}
	*lst = NULL;
}
