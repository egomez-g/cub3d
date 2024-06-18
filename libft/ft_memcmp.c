/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:28:29 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/09/14 10:06:14 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *buff1, const void *buff2, size_t count)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	i = 0;
	b1 = (unsigned char *)buff1;
	b2 = (unsigned char *)buff2;
	while (i < count)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		++i;
	}
	return (0);
}
