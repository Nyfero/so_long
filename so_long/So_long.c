/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 16:09:53 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 1)
		ft_error(1);
	else if (argc > 2)
		ft_error(2);
	ft_parsing(&map, argv[1]);
	map.mlx = mlx_init();
	if (!map.mlx)
		ft_error(0);
	ft_img_init(&map);
	map.mv = 0;
	map.pl.x = 0;
	map.pl.y = 0;
	map.win = mlx_new_window(map.mlx, (map.x * 50), (map.y * 50), "So_long");
	ft_display(&map);
	mlx_key_hook(map.win, keyboard, &map);
	mlx_hook(map.win, 12, 1L << 15, ft_display, &map);
	mlx_hook(map.win, 33, 1L << 5, ft_close, &map);
	mlx_loop(map.mlx);
}

void	ft_img_init(t_map *map)
{
	map->fl.img = mlx_xpm_file_to_image(map->mlx, "./img/Grass.xpm", \
	&map->fl.width, &map->fl.height);
	map->wl.img = mlx_xpm_file_to_image(map->mlx, "./img/Wall.xpm", \
	&map->wl.width, &map->wl.height);
	map->ck.img = mlx_xpm_file_to_image(map->mlx, "./img/Cookie.xpm", \
	&map->ck.width, &map->ck.height);
	map->end.img = mlx_xpm_file_to_image(map->mlx, "./img/End.xpm", \
	&map->end.width, &map->end.height);
	map->pl.i.img = mlx_xpm_file_to_image(map->mlx, "./img/Player.xpm", \
	&map->pl.i.width, &map->pl.i.height);
	if (map->pl.i.img == NULL || map->fl.img == NULL|| map->wl.img == NULL
	|| map->ck.img == NULL || map->end.img == NULL)
	{
		ft_free_img(map);
		ft_free_ls(map->map);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		ft_error(3);
	}
}

int	keyboard(int keycode, t_map *map)
{
	if (keycode == 65307)
		ft_close(map);
	else if (keycode == 122)
		ft_move_up(map);
	else if (keycode == 115)
		ft_move_down(map);
	else if (keycode == 113)
		ft_move_left(map);
	else if (keycode == 100)
		ft_move_right(map);
	ft_display(map);
	return (0);
}

void	ft_win(t_map *map)
{
	ft_putstr("Number of move :");
	ft_putnbr(++map->mv);
	ft_putchar('\n');
	ft_putstr("Victory");
	ft_putchar('\n');
	ft_close(map);
}

int	ft_close(t_map *map)
{
	ft_free_img(map);
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	ft_free_ls(map->map);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(0);
}
