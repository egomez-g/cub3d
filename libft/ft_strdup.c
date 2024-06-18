/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:59:29 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/26 10:20:01 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = ft_strlen(s);
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (p);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
