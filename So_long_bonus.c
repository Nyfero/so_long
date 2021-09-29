/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/29 18:34:10 by gsap             ###   ########.fr       */
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
	ft_parsing_bonus(&map, argv[1]);
	map.mlx = mlx_init();
	if (!map.mlx)
		ft_error(0);
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
	map->img.path = "./img/Ennemie_explode.xpm";
	while(i++ < 575)
	{
		map->img.img = mlx_xpm_file_to_image(map->mlx, map->img.path, \
			&map->img.width, &map->img.height);
		if (map->img.img == NULL)
			ft_error(3);
		mlx_put_image_to_window(map->mlx, map->win, \
			map->img.img, (map->enm[tmp].x * 50), (map->enm[tmp].y * 50));
	}
	i = 0;
	map->img.path = "./img/player_animation/pl_dd_1.xpm";
	while(i++ < 1000)
		ft_place_player(map);
	i = 0;
	map->img.path = "./img/player_animation/pl_dd_2.xpm";
	while(i++ < 2000)
		ft_place_player(map);
	ft_putstr("Perdu");
	ft_putchar('\n');
	ft_end(map);
}

void	ft_win_bonus(t_map *map)
{
	ft_putstr("Victoire");
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
