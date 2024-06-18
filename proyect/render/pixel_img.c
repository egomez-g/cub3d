/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:59 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/27 12:53:45 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

t_color	get_color(int red, int green, int blue)
{
	t_color	color;

	color.r = red;
	color.g = green;
	color.b = blue;
	return (color);
}

void	put_pixel_to_image(t_game *game, int x, int y, t_color color)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*image;
	int		pixel_position;

	if (y > WINDOW_HEIGHT || y < 0 || x > WINDOW_WIDTH || x < 0)
		return ;
	image = mlx_get_data_addr(game->image, \
	&bits_per_pixel, &size_line, &endian);
	pixel_position = (y * size_line) + (x * (bits_per_pixel / 8));
	image[pixel_position + 2] = (create_rgb(color.r, color.g, color.b) \
	& 0xFF0000) >> 16;
	image[pixel_position + 1] = (create_rgb(color.r, color.g, color.b) \
	& 0x00FF00) >> 8;
	image[pixel_position] = create_rgb(color.r, color.g, color.b) \
	& 0x0000FF;
}

t_color	pixel_on_img(int x, int y, void *img, int endian)
{
	t_color	color;
	int		pixel_position;
	int		bits_per_pixel;
	int		size_line;
	char	*image;

	image = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	pixel_position = (y * size_line) + (x * (bits_per_pixel / 8));
	color.r = image[pixel_position + 2];
	color.g = image[pixel_position + 1];
	color.b = image[pixel_position];
	return (color);
}
