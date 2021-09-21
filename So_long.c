/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/21 16:25:48 by gsap             ###   ########.fr       */
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
	map.mv = 0;
	map.pl.x = 0;
	map.pl.y = 0;
	map.win = mlx_new_window(map.mlx, (map.x * 50), (map.y * 50), "So_long");
	ft_display(&map);
	mlx_key_hook(map.win, keyboard, &map);
	mlx_hook(map.win, 12, 1L << 15, ft_display, &map);
	mlx_hook(map.win, 33, 1L << 5, ft_end, &map);
	mlx_loop(map.mlx);
}

int	keyboard(int keycode, t_map *map)
{
	if (keycode == 65307)
		ft_end(map);
	else if (keycode == 122)
		ft_move_left(map);
	else if (keycode == 115)
		ft_move_down(map);
	else if (keycode == 113)
		ft_move_up(map);
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
	ft_end(map);
}

int	ft_end(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img.img);
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	ft_free_ls(map->map);
	exit(0);
}
