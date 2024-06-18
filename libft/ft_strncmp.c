/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:06:15 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/01/04 15:04:08 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 0)
		return (0);
	while (i < count - 1 && str1[i] == str2[i] && str1[i] != '\0')
		++i;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
