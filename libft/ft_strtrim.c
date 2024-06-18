/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:24:29 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/26 10:20:38 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fnd(char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] != '\0' && fnd(s1[start], set) == 1)
		++start;
	end = ft_strlen(s1);
	while (end > 0 && fnd(s1[end -1], set) == 1)
		--end;
	if (start >= end)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (end - start + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1 + start, end - start + 1);
	return (p);
}
