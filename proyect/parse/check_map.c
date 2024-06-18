/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:40 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/27 13:07:57 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char	**make_map(t_game *game, t_gnl *str_map, int x, int y)
{
	int		i;
	char	**new_map;

	i = 0;
	game->max_x = x - 1;
	game->max_y = y - 1;
	new_map = (char **)malloc(sizeof(char *) * y + 1);
	if (!new_map)
		return (NULL);
	while (i < y)
	{
		new_map[i] = (char *)malloc(sizeof(char) * (x + 1));
		if (!new_map[i])
		{
			free_strs(new_map);
			exit(1);
		}
		fill_map_line(str_map, new_map, x, i);
		++i;
		str_map = str_map->next;
	}
	new_map[i] = NULL;
	return (new_map);
}

static void	create_map(t_gnl *str_map, t_game *game)
{
	t_gnl	*i;
	int		x;
	int		y;
	int		len;

	x = 0;
	y = 0;
	i = str_map;
	while (i)
	{
		len = 0;
		while (i->content[len])
			len++;
		if (len > x)
			x = len;
		i = i->next;
		++y;
	}
	game->map = make_map(game, str_map, x, y);
}

static void	measure_map(t_gnl *str_map, t_game *game)
{
	t_gnl	*i;
	int		j;
	int		flag;

	i = str_map;
	while (i)
	{
		j = 0;
		flag = 0;
		while (i->content[j])
		{
			if (i->content[j] != '1' && i->content[j] != '0' && \
			i->content[j] != 'N' && i->content[j] != 'S' && \
			i->content[j] != 'E' && i->content[j] != 'W' && \
			i->content[j] != '\n' && i->content[j] != ' ')
				flag = 1;
			++j;
		}
		if (i->content[0] == '\n')
			flag = 1;
		if (!flag)
			break ;
		i = i->next;
	}
	create_map(i, game);
}

static void	check_map_char(t_game *game)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			check_char_aux(game, i, j, &flag);
			j++;
		}
		i++;
	}
}

void	check_map(t_gnl *str_map, t_game *game)
{
	int	x;
	int	y;

	measure_map(str_map, game);
	check_map_char(game);
	check_map_walls(game);
	game->num_doors = 0;
	y = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (game->map[y][x] == ' ')
				game->map[y][x] = '0';
			else if (game->map[y][x] == 'D')
				game->num_doors++;
			x++;
		}
		y++;
	}
}
