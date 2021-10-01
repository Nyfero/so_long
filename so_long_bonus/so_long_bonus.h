/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/10/01 14:57:20 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_ennemie
{
	int	x;
	int	y;
	int	lm;
}	t_enm;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_img_ennemie
{
	t_img	n;
	t_img	e;
}	t_img_enm;

typedef struct s_player
{
	int		x;
	int		y;

	t_img	i;
	t_img	md1;
	t_img	md2;
	t_img	mu1;
	t_img	mu2;
	t_img	ml1;
	t_img	ml2;
	t_img	ml3;
	t_img	mr1;
	t_img	mr2;
	t_img	mr3;
	t_img	dd1;
	t_img	dd2;
}	t_player;

typedef struct s_map
{
	void		*mlx;
	void		*win;

	t_img		img;
	t_img		fl;
	t_img		wl;
	t_img		ck;
	t_img		end;
	t_player	pl;
	t_enm		*enm;
	t_img_enm	ie;

	int			x;
	int			y;
	char		**map;

	int			mv;
	size_t		c;
	size_t		p;
	size_t		e;
	size_t		a;
}	t_map;

int		main(int argc, char **argv);
int		keyboard(int keycode, t_map *map);
void	ft_win_bonus(t_map *map);
void	ft_loose(t_map *map, int tmp);
int		ft_end(t_map *map);

void	ft_parsing_bonus(t_map *map, char *file);
void	ft_create_map(t_map *map, char *file);
void	ft_save_map_bonus(t_map *map, int i, int j, char *tmp);
void	ft_map_size(t_map *map, char *file);
void	ft_check_file(char *file);

void	ft_check_valid_map(t_map *map, char *file);
void	ft_map_closed(t_map *map, char *file);
void	ft_well_composed_bonus(t_map *map, char *file);
void	ft_check_in_map(t_map *map, int fd);

void	ft_error(int err);
void	ft_error_parsing(int err, char *tmp);

int		ft_display_bonus(t_map *map);
void	ft_place_player(t_map *map, t_img player);
void	ft_place_ennemie(t_map *map);
void	ft_pick_image_bonus(t_map *map, int i, int j);
void	ft_compt_bonus(t_map *map);

void	ft_move_up_bonus(t_map *map);
void	ft_move_down_bonus(t_map *map);
void	ft_move_left_bonus(t_map *map);
void	ft_move_right_bonus(t_map *map);

void	ft_go_up(t_map *map);
void	ft_go_down(t_map *map);
void	ft_go_right(t_map *map);
void	ft_go_left(t_map *map);

void	ft_init_img(t_map *map);
void	ft_init_player_anm(t_map *map);
void	ft_init_rest(t_map *map);
void	ft_free_img(t_map *map);
void	ft_more_free_img(t_map *map);

void	ft_move_ennemie(t_map *map);
void	ft_enm_up(t_map *map, int i);
void	ft_enm_down(t_map *map, int i);
void	ft_enm_left(t_map *map, int i);
void	ft_enm_right(t_map *map, int i);

#endif
