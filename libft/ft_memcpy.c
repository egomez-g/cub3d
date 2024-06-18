/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:18:17 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/09/14 14:43:18 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = 0;
	s = (const char *)src;
	d = (char *) dest;
	if (!dest && !src)
		return (NULL);
	while (i < count)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}
