/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:00:56 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/01/16 14:09:06 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr( const char *str, int c)
{
	char	*p;

	p = (char *)str;
	while (*p != '\0')
		++p;
	while (p != str)
	{
		if (*p == (char)c)
			return (p);
		--p;
	}
	if (*p == (char)c)
		return (p);
	return (0);
}
