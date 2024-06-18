/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:36 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/22 12:18:40 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_char_aux(t_game *game, int i, int j, int *flag)
{
	if (game->map[i][j] != '1' && game->map[i][j] != '0' && \
	game->map[i][j] != 'N' && game->map[i][j] != 'S' && \
	game->map[i][j] != 'E' && game->map[i][j] != 'W' && \
	game->map[i][j] != ' ' && game->map[i][j] != 'D' )
	{
		printf("caracter invalido\n");
		exit (1);
	}
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || \
		game->map[i][j] == 'E' || game->map[i][j] == 'W')
	{
		game->player.y = (i * 64) + 32;
		game->player.x = (j * 64) + 32;
		game->player.a = get_player_angle(game->map[i][j]);
		if (*flag)
		{
			printf("caracter de personaje repetido\n");
			exit (1);
		}
		*flag = 1;
	}
}

void	fill_map_line(t_gnl *str_map, char**new_map, int x, int i)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (j < x)
	{
		if (str_map->content[j] && str_map->content[j] != '\n' && flag != 1)
			new_map[i][j] = str_map->content[j];
		else
		{
			flag = 1;
			new_map[i][j] = ' ';
		}
		++j;
	}
	new_map[i][j] = '\0';
}

static int	space_in_perimeter(char **map, int x, int y)
{
	if (map[y - 1][x] == ' ' || \
		map[y][x - 1] == ' ' || \
		map[y][x] == ' ' || \
		map[y][x + 1] == ' ' || \
		map[y + 1][x] == ' ')
	{
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (1);
	}
	return (0);
}

static void	check_perimeter(t_game *game, int x, int y)
{
	if (x == game->max_x || y == 0 || y == game->max_y || x == 0)
	{
		if (game->map[y][x] != '1' && game->map[y][x] != ' ')
		{
			printf ("Error, invalid border x: %d y: %d", x, y);
			exit(1);
		}
	}
	else
	{
		if (space_in_perimeter(game->map, x, y))
		{
			printf ("Error, invalid border x: %d y: %d", x, y);
			exit(1);
		}
	}
}

void	check_map_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			check_perimeter(game, x, y);
			x++;
		}
		y++;
	}
}
