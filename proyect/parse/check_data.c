/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:31 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/21 17:35:53 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	fill_texture(t_game *game, char *str)
{
	char	**data;

	data = ft_split(str, ' ');
	if (!data)
		return (1);
	if (!data[1])
		return (free_strs(data), 1);
	if (!ft_strncmp(str, "NO", 2))
		game->n_texture = ft_substr(data[1], 0, ft_strlen(data[1]) - 1);
	else if (!ft_strncmp(str, "SO", 2))
		game->s_texture = ft_substr(data[1], 0, ft_strlen(data[1]) - 1);
	else if (!ft_strncmp(str, "WE", 2))
		game->w_texture = ft_substr(data[1], 0, ft_strlen(data[1]) - 1);
	else if (!ft_strncmp(str, "EA", 2))
		game->e_texture = ft_substr(data[1], 0, ft_strlen(data[1]) - 1);
	free_strs(data);
	return (0);
}

static int	fill_color(t_game *game, char *str)
{
	char	**data;
	char	**color_vals;
	int		error_flag;

	data = ft_split(str, ' ');
	error_flag = 0;
	if (!data)
		return (1);
	if (!data[1])
		return (free_strs(data), 1);
	color_vals = ft_split(data[1], ',');
	if (ft_strncmp(str, "C", 1))
	{
		game->floor_color.r = ft_atoi(color_vals[0]);
		game->floor_color.g = ft_atoi(color_vals[1]);
		game->floor_color.b = ft_atoi(color_vals[2]);
	}
	if (ft_strncmp(str, "F", 1))
	{
		game->celing_color.r = ft_atoi(color_vals[0]);
		game->celing_color.g = ft_atoi(color_vals[1]);
		game->celing_color.b = ft_atoi(color_vals[2]);
	}
	return (free_strs(data), free_strs(color_vals), 0);
}

static int	fill_data(t_game *game, char *str)
{
	if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) || \
		!ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
	{
		if (fill_texture(game, str) == 1)
			return (1);
	}
	else if (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
	{
		if (fill_color(game, str) == 1)
			return (1);
	}
	return (0);
}

static int	check_fill(t_game *game)
{
	if ((game->celing_color.r < 0 || game->celing_color.r > 255) || \
		(game->celing_color.g < 0 || game->celing_color.g > 255) || \
		(game->celing_color.b < 0 || game->celing_color.b > 255))
		return (1);
	if ((game->floor_color.r < 0 || game->floor_color.r > 255) || \
		(game->floor_color.g < 0 || game->floor_color.g > 255) || \
		(game->floor_color.b < 0 || game->floor_color.b > 255))
		return (1);
	if (!(game->n_texture) || \
		!(game->s_texture) || \
		!(game->e_texture) || \
		!(game->w_texture))
		return (1);
	return (0);
}

void	check_data(t_gnl *str_map, t_game *game)
{
	t_gnl	*i;

	i = str_map;
	game->n_texture = NULL;
	game->s_texture = NULL;
	game->w_texture = NULL;
	game->e_texture = NULL;
	game->player.a = -1;
	while (i)
	{
		if (fill_data(game, i->content) == 1)
			exit (1);
		i = i->next;
	}
	if (check_fill(game) == 1)
	{
		printf("WRONG DATA\n");
		exit (1);
	}
}
