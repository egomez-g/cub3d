/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:15:08 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/09/14 09:57:37 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *buffer, int c, size_t count)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)buffer;
	while (i < count)
	{
		if (a[i] == (char)c)
			return (&a[i]);
		++i;
	}
	return (NULL);
}
