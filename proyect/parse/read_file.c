/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:50 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/20 16:54:51 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}

static void	add_stack(char *line, t_gnl **list)
{
	t_gnl	*nodo;
	t_gnl	*i;

	nodo = (t_gnl *) malloc (sizeof(t_gnl));
	if (!nodo)
		return ;
	nodo->content = line;
	nodo->next = NULL;
	i = *list;
	if (*list)
	{
		while (i->next)
			i = i->next;
		i->next = nodo;
	}
	else
		*list = nodo;
}

t_gnl	*get_file(char *file)
{
	t_gnl	*list;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	list = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_stack(line, &list);
	}
	return (list);
}
