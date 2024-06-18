/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:53 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/26 10:19:20 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	size_t	val;

	val = size * num;
	if (val > SIZE_MAX)
		return (NULL);
	p = malloc(val);
	if (p == NULL)
		return (p);
	ft_bzero(p, val);
	return (p);
}
