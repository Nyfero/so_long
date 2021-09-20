/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/20 17:37:59 by gsap             ###   ########.fr       */
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
	map.win = mlx_new_window(map.mlx, (map.x * 50), (map.y * 50), "So_long");
	ft_display(&map);
	mlx_key_hook(map.win, keyboard, &map);

	mlx_loop(map.mlx);
}

int	ft_mouse(int mouse, int x, int y, t_map *map)
{
	(void)mouse;
	(void)map;
	if (x == 0 && y == 1080)
		exit(0);
	return (0);
}

int	keyboard(int keycode, t_map *map)
{
	if (keycode == 65307)
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
		ft_free_ls(map->map);
		exit(0);
	}
	else if (keycode == 122)
		ft_move_left(map);
	else if (keycode == 115)
		ft_move_down(map);
	else if (keycode == 113)
		ft_move_up(map);
	else if (keycode == 100)
		ft_move_right(map);
	mlx_clear_window(map->mlx, map->win);
	ft_display(map);
	return (0);
}
