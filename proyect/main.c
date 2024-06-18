/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:56 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/04/01 12:19:07 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_game(t_game *game)
{
	free (game->doors);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->image);
	mlx_destroy_image(game->mlx, game->ui);
	mlx_destroy_image(game->mlx, game->door_tex);
	mlx_destroy_image(game->mlx, game->n_tex);
	mlx_destroy_image(game->mlx, game->s_tex);
	mlx_destroy_image(game->mlx, game->e_tex);
	mlx_destroy_image(game->mlx, game->w_tex);
	exit (0);
}

static void	initialize_textures(t_game *game)
{
	int	size;

	size = 0;
	game->n_tex = mlx_xpm_file_to_image(game->mlx, \
	game->n_texture, &size, &size);
	game->s_tex = mlx_xpm_file_to_image(game->mlx, \
	game->s_texture, &size, &size);
	game->e_tex = mlx_xpm_file_to_image(game->mlx, \
	game->e_texture, &size, &size);
	game->w_tex = mlx_xpm_file_to_image(game->mlx, \
	game->w_texture, &size, &size);
	game->ui = mlx_xpm_file_to_image(game->mlx, \
	"./proyect/textures/ui.xpm", &size, &size);
	game->door_tex = mlx_xpm_file_to_image(game->mlx, \
	"./proyect/textures/door.xpm", &size, &size);
	game->ui_tex0 = mlx_xpm_file_to_image(game->mlx, \
	"./proyect/textures/ui0.xpm", &size, &size);
	game->ui_tex1 = mlx_xpm_file_to_image(game->mlx, \
	"./proyect/textures/ui1.xpm", &size, &size);
	game->ui_tex2 = mlx_xpm_file_to_image(game->mlx, \
	"./proyect/textures/ui2.xpm", &size, &size);
	game->ui_tex3 = mlx_xpm_file_to_image(game->mlx, \
	"./proyect/textures/ui3.xpm", &size, &size);
}

static void	initialize(t_game *game)
{
	int		size;

	size = 0;
	game->player.speed = 0;
	game->player.v_speed = 0;
	game->collision = 0;
	game->eye = 0;
	initialize_textures(game);
	if (!game->n_tex || !game->s_tex || !game->e_tex || !game->w_tex)
	{
		printf ("Error: wrong path to texture");
		exit (1);
	}
	initialize_doors(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("BAD INPUT\n"), 1);
	parse(argv[1], &game);
	game.mlx = mlx_init();
	initialize(&game);
	game.image = mlx_new_image(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "joego pero muuy guapo");
	mlx_mouse_move(game.win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_mouse_hide();
	mlx_hook(game.win, 2, 0, key_press, &game);
	mlx_hook(game.win, 3, 0, key_release, &game);
	mlx_hook(game.win, 6, 0, mouse_hook, &game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	exit (0);
}
