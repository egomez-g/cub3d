/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:55:23 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/28 20:14:19 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	render_wall(t_game *game, int x, int len, float dist)
{
	float		i_y;
	float		size;
	int			lerp_val;
	t_color		color;

	size = WINDOW_HEIGHT - len;
	i_y = size / 2;
	while (i_y < WINDOW_HEIGHT - size / 2)
	{
		lerp_val = 63 * ((i_y - (size / 2)) / (WINDOW_HEIGHT - (size)));
		if (lerp_val < 0)
			lerp_val = 0;
		color = pixel_on_img(dist, lerp_val, game->ray.new_tex, 0);
		if (i_y < WINDOW_HEIGHT && i_y > -1)
			put_pixel_to_image(game, x, i_y, color);
		i_y++;
		if (i_y < -PLANK_CONST)
			break ;
	}
}

static float	get_tex(t_game *game)
{
	if ((int)game->ray.c_y % 64 == 0 && (int)game->ray.c_x % 64 == 0)
	{
		game->ray.new_tex = game->ray.last_tex;
		return ((int)game->ray.c_x % 64);
	}
	else if ((int)game->ray.c_y % 64 == 0)
	{
		if (game->ray.sen < 0)
			game->ray.c_y -= 1;
		if (game->ray.c_y > game->player.y)
			game->ray.new_tex = game->n_tex;
		else
			game->ray.new_tex = game->s_tex;
		return ((int)game->ray.c_x % 64);
	}
	else
	{
		if (game->ray.cosen < 0)
			game->ray.c_x -= 1;
		if (game->ray.c_x > game->player.x)
			game->ray.new_tex = game->w_tex;
		else
			game->ray.new_tex = game->e_tex;
		return ((int)game->ray.c_y % 64);
	}
}

static void	wall_dir(t_game *game, int x, float dist)
{
	float	aux;
	void	*tex;

	if (dist < 12)
		return ;
	aux = 0;
	tex = NULL;
	if (dist > 1024)
		dist = 1024;
	if (game->ray.cosen < 0)
		game->ray.c_x += 1;
	if (game->ray.sen < 0)
		game->ray.c_y += 1;
	aux = get_tex(game);
	game->ray.last_tex = game->ray.new_tex;
	if (game->map[(int)game->ray.c_y / 64][(int)game->ray.c_x / 64] == 'D' && \
	door_is_closed(game, (int)game->ray.c_y / 64, (int)game->ray.c_x / 64))
	{
		game->ray.new_tex = game->door_tex;
		render_wall(game, x, PLANK_CONST / dist, aux);
	}
	else
		render_wall(game, x, PLANK_CONST / dist, aux);
}

static void	find_wall(t_game *game, float angle, float distorsion, int x)
{
	float	dist;
	float	distorsion_cos;

	game->ray.c_y = game->player.y;
	game->ray.c_x = game->player.x;
	game->ray.cosen = cos(angle * M_PI / 180);
	game->ray.sen = -sin(angle * M_PI / 180);
	distorsion_cos = cos(distorsion * M_PI / 180);
	while (game->ray.c_y < (game->max_y + 1) * 64 && \
	game->ray.c_x < game->max_x * 64 && game->ray.c_y > 0 && game->ray.c_x > 0)
	{
		if (game->map[(int)game->ray.c_y / 64] \
		[(int)game->ray.c_x / 64] == '1' || (game->map[(int)game->ray.c_y / 64] \
		[(int)game->ray.c_x / 64] == 'D' && door_is_closed(game, \
		(int)game->ray.c_y / 64, (int)game->ray.c_x / 64)))
		{
			dist = sqrt(pow(game->ray.c_x - game->player.x, 2.0) + \
			pow(game->ray.c_y - game->player.y, 2.0)) \
			* distorsion_cos;
			wall_dir(game, x, dist);
			break ;
		}
		game->ray.c_y = game->ray.c_y + game->ray.sen;
		game->ray.c_x = game->ray.c_x + game->ray.cosen;
	}
}

void	render_raycast_v2(t_game *game)
{
	int		x;
	float	angle;
	float	diff;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		angle = lerp(game->player.a + 25 + game->eye, \
		game->player.a - 25 - game->eye, (float)x / (float)WINDOW_WIDTH);
		if (angle < 0)
			angle += 360;
		else if (angle >= 360)
			angle -= 360;
		diff = angle - game->player.a;
		find_wall(game, angle, diff, x);
		x++;
	}
}
