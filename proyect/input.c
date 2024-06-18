/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:55:43 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/04/01 12:23:31 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_player_vector(t_game *game)
{
	if (game->collision && game->a_press)
		game->player.v_speed = 45;
	else if (game->collision && game->d_press)
		game->player.v_speed = 315;
	else
		game->player.v_speed = 0;
}

void	move(t_game *game, int dir)
{
	game->player.speed = 7;
	if (dir == 0)
		get_player_vector(game);
	if (dir == 2)
	{
		if (game->collision && game->a_press)
			game->player.v_speed = 135;
		else if (game->d_press && game->collision)
			game->player.v_speed = 225;
		else
			game->player.v_speed = 180;
	}
	if (dir == 1)
	{
		if (game->s_press && game->collision)
			game->player.v_speed = 135;
		else
			game->player.v_speed = 90;
	}
	if (dir == 3)
		game->player.v_speed = 270;
}

static void	key_hook_aux(int keycode, t_game *game)
{
	if (keycode == KEY_SPACE)
	{
		if (game->collision)
			game->collision = 0;
		else
			game->collision = 1;
	}
	if (keycode == KEY_E)
		open_door(game);
	if (keycode == KEY_Q)
	{
		if (game->eye)
			game->eye = 0;
		else
			game->eye = 20;
	}
	else if (keycode == KEY_ESCAPE)
		exit_game(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->w_press = 1;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		game->a_press = 1;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->s_press = 1;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->d_press = 1;
	key_hook_aux(keycode, game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->w_press = 0;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		game->a_press = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->s_press = 0;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->d_press = 0;
	return (0);
}
