/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:27 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/26 10:20:27 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	found(char *src, const char *fnd, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] == fnd[i] && fnd[i] != '\0' && i < len)
		++i;
	if (fnd[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *src, const char *fnd, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *) src;
	if (fnd[0] == '\0')
		return (p);
	while (i < len && src[i] != '\0')
	{
		if (p[i] == fnd[0])
			if (found(&p[i], fnd, len - i) == 1)
				return (&p[i]);
		++i;
	}
	return (NULL);
}
