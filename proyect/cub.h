/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:32:41 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/03/28 19:36:57 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define BUFFER_SIZE 42
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define PLANK_CONST 50000

enum
{
	KEY_A		= 0,
	KEY_S		= 1,
	KEY_D		= 2,
	KEY_W		= 13,
	KEY_SPACE	= 49,
	KEY_E		= 14,
	KEY_Q		= 12,
	KEY_ESCAPE	= 53,
	KEY_LEFT	= 123,
	KEY_RIGHT	= 124,
	KEY_DOWN	= 125,
	KEY_UP		= 126
};

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_gnl
{
	char			*content;
	struct s_gnl	*next;
}					t_gnl;

typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_color;

//_____________________________________________________________

typedef struct s_raycast
{
	float	c_x;
	float	c_y;
	float	cosen;
	float	sen;
	void	*last_tex;
	void	*new_tex;
}	t_raycast;

typedef struct s_door
{
	int	x;
	int	y;
	int	open;
}	t_door;

typedef struct s_player
{
	float	x;
	float	y;
	float	a;
	int		mouse_x;
	int		mouse_y;
	float	speed;
	float	v_speed;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*image;
	void		*ui;
	void		*ui_tex0;
	void		*ui_tex1;
	void		*ui_tex2;
	void		*ui_tex3;
	void		*n_tex;
	void		*s_tex;
	void		*w_tex;
	void		*e_tex;
	void		*door_tex;

	char		*n_texture;
	char		*s_texture;
	char		*e_texture;
	char		*w_texture;
	t_color		n_color;
	t_color		s_color;
	t_color		e_color;
	t_color		w_color;

	void		*wall_texture;

	t_color		floor_color;
	t_color		celing_color;
	int			collision;
	int			eye;
	int			num_doors;

	int			max_x;
	int			max_y;
	char		**map;

	int			w_press;
	int			s_press;
	int			d_press;
	int			a_press;

	t_player	player;
	t_raycast	ray;
	t_door		*doors;
}	t_game;

void			exit_game(t_game *game);

//Parse
void			parse(char *file, t_game *game);
t_gnl			*get_file(char *file);
void			free_strs(char **strs);
void			fill_map_line(t_gnl *str_map, char**new_map, int x, int i);

void			check_data(t_gnl *str_map, t_game *game);
void			check_map(t_gnl *str_map, t_game *game);
void			check_map_walls(t_game *game);
void			check_char_aux(t_game *game, int i, int j, int *flag);
void			initialize_doors(t_game *game);
void			open_door(t_game *game);
int				door_is_closed(t_game *game, int y, int x);
//Input
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				mouse_hook(int x, int y, t_game *game);
int				close_win(t_game *game);
int				update(t_game *game);
void			move(t_game *game, int dir);

//Render
//void	render_raycast(t_game *game);

int				render(t_game *game);
void			put_pixel_to_image(t_game *game, int x, int y, t_color color);
t_color			pixel_on_img(int x, int y, void *img, int endian);
void			render_raycast_v2(t_game *game);

//Render Math
float			lerp(float a, float b, float f);
int				get_player_angle(char c);

//color
t_color			get_color(int red, int green, int blue);
unsigned long	create_rgb(int r, int g, int b);

//gnl
char			*get_next_line(int fd);
int				ft_find_line(char *buff);
char			*gnl_strjoin(char *s1, char const *s2);

#endif