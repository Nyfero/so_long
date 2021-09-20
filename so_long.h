/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/20 17:47:01 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_img
{
	void	*img;

	char	*path;
	int		wid;
	int		hei;
}	t_img;

typedef struct s_map
{
	void		*mlx;
	void		*win;

	int			x;
	int			y;
	char		**map;

	size_t		c;
	size_t		p;
	size_t		e;

	t_player	pl;
}	t_map;

int	main(int argc, char **argv);
int	ft_mouse(int mouse, int x, int y, t_map *map);
int	keyboard(int keycode, t_map *map);

void	ft_error(int err);
void 	ft_error_parsing(int err);

void	ft_parsing(t_map *map, char *file);
void	ft_save_map(t_map *map, char *file);

void	ft_map_size(t_map *map, char *file);
void	ft_check_file(char *file);
void	ft_check_valid_map(t_map *map, char *file);
void	ft_map_closed(t_map * map, char *file);
void	ft_well_composed(t_map *map, char *file);

void	ft_display(t_map *map);

void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);
void 	ft_move_left(t_map *map);
void 	ft_move_right(t_map *map);


#endif
