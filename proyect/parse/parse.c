/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:45 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/21 17:37:03 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	check_name(char *file)
{
	char	*aux;

	aux = file + (ft_strlen(file) - 4);
	if (ft_strncmp(aux, ".cub", 4) != 0)
	{
		printf("Invalid file\n");
		exit(1);
	}
}

static void	free_list(t_gnl *list)
{
	t_gnl	*i;

	while (list)
	{
		i = list->next;
		free(list->content);
		free(list);
		list = i;
	}
}

void	parse(char *file, t_game *game)
{
	t_gnl	*data;

	check_name(file);
	data = get_file(file);
	check_data(data, game);
	check_map(data, game);
	free_list(data);
	if (!game->n_texture || !game->s_texture || \
	!game->w_texture || !game->e_texture)
	{
		printf("Error: not all textures\n");
		exit (1);
	}
	if (game->player.a == -1)
	{
		printf("Error: there's no player\n");
		exit (1);
	}
}
