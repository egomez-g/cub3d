/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:19:05 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/19 16:50:50 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int str, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (str > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - str))
		len = ft_strlen(s) - str;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (p);
	if (ft_strlen(s) <= str)
		len = 0;
	while (i < len && s[str + i] != '\0')
	{
		p[i] = s[str + i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
