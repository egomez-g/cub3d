/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:55:06 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:34 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float	lerp(float a, float b, float f)
{
	return (a * (1.0 - f) + (b * f));
}

int	get_player_angle(char c)
{
	if (c == 'N')
		return (90);
	if (c == 'S')
		return (270);
	if (c == 'E')
		return (0);
	return (180);
}
