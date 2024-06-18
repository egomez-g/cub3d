/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:34:16 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/27 12:58:36 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	mini_door(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	if (game->map[y][x] != 'D')
		return (0);
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

static void	draw_minimap_tile(int x, int y, t_game *game, t_color white)
{
	int		i_x;
	int		i_y;
	t_color	black;
	t_color	red;

	black = get_color(0, 0, 0);
	red = get_color(255, 0, 0);
	i_y = 0;
	while (i_y < 10)
	{
		i_x = 0;
		while (i_x++ < 10)
		{
			if (game->map[y][x] == '1' || mini_door(game, y, x))
				put_pixel_to_image(game, i_x + 10 + (x * 10), \
				i_y + 10 + (y * 10), white);
			else if (game->map[y][x + 1] != '\0' )
				put_pixel_to_image(game, i_x + 10 + (x * 10), \
				i_y + 10 + (y * 10), black);
			if (y == (int)game->player.y / 64 && x == (int)game->player.x / 64)
				put_pixel_to_image(game, i_x + 10 + (x * 10), \
				i_y + 10 + (y * 10), red);
		}
		i_y++;
	}
}

static void	draw_minimap(t_game *game)
{
	int		x;
	int		y;
	t_color	white;

	y = 0;
	white = get_color(255, 255, 255);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_minimap_tile(x, y, game, white);
			x++;
		}
		y++;
	}
}

static void	draw_bg(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				put_pixel_to_image(game, x, y, game->celing_color);
			else
				put_pixel_to_image(game, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}

int	render(t_game *game)
{
	static int	frame;

	frame += 1;
	update(game);
	mlx_clear_window(game->mlx, game->win);
	draw_bg(game);
	render_raycast_v2(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->ui_tex3, \
	WINDOW_WIDTH / 2 - 422, WINDOW_HEIGHT - 152);
	if ((frame - 20) / 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->ui_tex2, \
		WINDOW_WIDTH / 2 - 422, WINDOW_HEIGHT - 152);
	else if ((frame - 20) / 2 == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->ui_tex1, \
		WINDOW_WIDTH / 2 - 422, WINDOW_HEIGHT - 152);
	else if ((frame - 20) / 2 == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->ui_tex0, \
		WINDOW_WIDTH / 2 - 422, WINDOW_HEIGHT - 152);
	else if ((frame - 20) / 2 == 3)
		frame = 0;
	return (0);
}
