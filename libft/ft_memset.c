/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:20:27 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/09/14 10:33:12 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *dest, int c, size_t count)
{
	char	*p;
	size_t	i;

	p = (char *)dest;
	i = 0;
	while (i < count)
	{
		p[i] = c;
		++i;
	}
	return (dest);
}
