/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:22:01 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/06 09:51:29 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

char	*ft_get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		++i;
	if (buff[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		++i;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_resize_buff(char *buff)
{
	char	*aux;
	size_t	start;
	size_t	len;

	start = 0;
	if (!buff)
		return (NULL);
	while (buff[start] != '\n' && buff[start] != '\0')
		++start;
	++start;
	len = ft_strlen(buff);
	aux = ft_substr(buff, start, len);
	free(buff);
	return (aux);
}

char	*get_text(char *buff, int fd)
{
	char	*aux;
	int		n;

	while (ft_find_line(buff) == 0)
	{
		aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!aux)
			return (NULL);
		n = read(fd, aux, BUFFER_SIZE);
		if (n == -1)
		{
			free(aux);
			free(buff);
			buff = NULL;
			return (NULL);
		}
		aux[n] = '\0';
		if (n != 0)
			buff = gnl_strjoin(buff, aux);
		free(aux);
		aux = NULL;
		if (n < BUFFER_SIZE)
			break ;
	}
	return (buff);
}

char	*result(char **buff, char *aux)
{
	if (ft_find_line(*buff) == 1)
	{
		aux = ft_get_line(*buff);
		*buff = ft_resize_buff(*buff);
		if (!*buff[0])
		{
			free(*buff);
			*buff = NULL;
		}
		return (aux);
	}
	if (*buff)
	{
		if (*buff[0] == '\0')
			aux = NULL;
		else
			aux = ft_strdup(*buff);
		free(*buff);
		*buff = NULL;
		return (aux);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*aux;

	aux = NULL;
	if (ft_find_line(buff) == 1)
	{
		aux = ft_get_line(buff);
		buff = ft_resize_buff(buff);
		return (aux);
	}
	buff = get_text(buff, fd);
	if (!buff)
		return (NULL);
	return (result(&buff, aux));
}
