/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 18:36:39 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 1)
		ft_error(1);
	else if (argc > 2)
		ft_error(2);
	ft_parsing_bonus(&map, argv[1]);
	map.mlx = mlx_init();
	if (!map.mlx)
		ft_error(0);
	ft_init_img(&map);
	map.mv = 0;
	map.win = mlx_new_window(map.mlx, map.x * 50, map.y * 50, "So_long_bonus");
	ft_display_bonus(&map);
	mlx_key_hook(map.win, keyboard, &map);
	mlx_hook(map.win, 12, 1L << 15, ft_display_bonus, &map);
	mlx_hook(map.win, 33, 1L << 5, ft_end, &map);
	mlx_loop(map.mlx);
	return (0);
}

int	keyboard(int keycode, t_map *map)
{
	if (keycode == 65307)
		ft_end(map);
	else if (keycode == 122)
		ft_go_up(map);
	else if (keycode == 115)
		ft_go_down(map);
	else if (keycode == 113)
		ft_go_left(map);
	else if (keycode == 100)
		ft_go_right(map);
	ft_display_bonus(map);
	return (0);
}

void ft_loose(t_map *map, int tmp)
{
	int	i;

	i = 0;
	while(i++ < 4000)
	{
		mlx_put_image_to_window(map->mlx, map->win, \
			map->ie.e.img, (map->enm[tmp].x * 50), (map->enm[tmp].y * 50));
	}
	i = 0;
	while(i++ < 8000)
		ft_place_player(map, map->pl.dd1);
	i = 0;
	while(i++ < 16000)
		ft_place_player(map, map->pl.dd2);
	ft_putstr("Defeat");
	ft_putchar('\n');
	ft_end(map);
}

void	ft_win_bonus(t_map *map)
{
	ft_putstr("Victory");
	ft_putchar('\n');
	ft_end(map);
}

int	ft_end(t_map *map)
{
	ft_free_img(map);
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	ft_free_ls(map->map);
	free(map->enm);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(0);
}
