/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:53:25 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/26 10:19:26 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_size(long n)
{
	long	size;

	if (n < 0)
		n = -n;
	size = 1;
	if (n > 9)
		size += get_size(n / 10);
	else
		return (size);
	return (size);
}

static long	pow(long i)
{
	long	n;

	n = 1;
	while (i > 0)
	{
		n *= 10;
		--i;
	}
	return (n);
}

static void	cast(long n, long i, char *p, long size)
{
	if (i == 1)
	{
		p[0] = '-';
		i = 0;
		while (i < size)
		{
			p[i + 1] = (n / pow((size - 1 - i))) + '0';
			n = n % pow((size - 1 - i));
			++i;
		}
		p[i + 1] = '\0';
	}
	else
	{
		while (i < size)
		{
			p[i] = (n / pow((size - 1 - i))) + '0';
			n = n % pow((size - 1 - i));
			++i;
		}
		p[i] = '\0';
	}
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	long	size;
	long	num;

	num = n;
	size = get_size(num);
	if (num < 0)
	{
		i = 1;
		num *= -1;
		p = (char *)malloc(sizeof(char) * (size + 2));
	}
	else
	{
		i = 0;
		p = (char *)malloc(sizeof(char) * (size + 1));
	}
	if (p == NULL)
		return (NULL);
	cast(num, i, p, size);
	return (p);
}
