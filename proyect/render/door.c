/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:25:35 by egomez-g          #+#    #+#             */
/*   Updated: 2024/03/27 13:05:49 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	door_is_closed(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < game->num_doors)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
		{
			if (!game->doors[i].open)
				return (1);
		}
		i++;
	}
	return (0);
}

void	initialize_doors(t_game *game)
{
	int	y;
	int	x;
	int	i;

	game->doors = malloc (sizeof(t_door) * game->num_doors);
	if (!game->num_doors)
		return ;
	y = 0;
	i = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (game->map[y][x] == 'D')
			{
				game->doors[i].x = x;
				game->doors[i].y = y;
				game->doors[i].open = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void	cl_door(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < game->num_doors)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
			break ;
		i++;
	}
	if (game->doors[i].open)
		game->doors[i].open = 0;
	else
		game->doors[i].open = 1;
}

static void	open_door_aux(t_game *game)
{
	if (game->map[((int)game->player.y / 64) + 2] \
					[(int)game->player.x / 64] && \
		game->map[((int)game->player.y / 64) + 2] \
		[(int)game->player.x / 64] == 'D')
		cl_door(game, (int)game->player.y / 64 + 2, (int)game->player.x / 64);
	else if (game->map[((int)game->player.y / 64) - 2] \
	[(int)game->player.x / 64] && \
			game->map[((int)game->player.y / 64) - 2] \
			[(int)game->player.x / 64] == 'D')
		cl_door(game, (int)game->player.y / 64 - 2, (int)game->player.x / 64);
	else if (game->map[((int)game->player.y / 64)] \
	[((int)game->player.x / 64) + 2] && \
			game->map[((int)game->player.y / 64)] \
			[((int)game->player.x / 64) + 2] == 'D')
		cl_door(game, (int)game->player.y / 64, (int)game->player.x / 64 + 2);
	else if (game->map[((int)game->player.y / 64)] \
	[((int)game->player.x / 64) - 2] && \
			game->map[((int)game->player.y / 64)] \
			[((int)game->player.x / 64) - 2] == 'D')
		cl_door(game, (int)game->player.y / 64, (int)game->player.x / 64 - 2);
}

void	open_door(t_game *game)
{
	if (game->map[((int)game->player.y / 64) + 1][(int)game->player.x / 64] && \
		game->map[((int)game->player.y / 64) + 1] \
		[(int)game->player.x / 64] == 'D')
		cl_door(game, (int)game->player.y / 64 + 1, (int)game->player.x / 64);
	else if (game->map[((int)game->player.y / 64) - 1] \
	[(int)game->player.x / 64] && \
			game->map[((int)game->player.y / 64) - 1] \
			[(int)game->player.x / 64] == 'D')
		cl_door(game, (int)game->player.y / 64 - 1, (int)game->player.x / 64);
	else if (game->map[((int)game->player.y / 64)] \
	[((int)game->player.x / 64) + 1] && \
			game->map[((int)game->player.y / 64)] \
			[((int)game->player.x / 64) + 1] == 'D')
		cl_door(game, (int)game->player.y / 64, (int)game->player.x / 64 + 1);
	else if (game->map[((int)game->player.y / 64)] \
	[((int)game->player.x / 64) - 1] && \
			game->map[((int)game->player.y / 64)] \
			[((int)game->player.x / 64) - 1] == 'D')
		cl_door(game, (int)game->player.y / 64, (int)game->player.x / 64 - 1);
	open_door_aux(game);
}
