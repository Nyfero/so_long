/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 14:42:37 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			ft_pick_image(map, i, j);
	}
	return (0);
}

void	ft_pick_image(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->wl.img, (j * 50), (i * 50));
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->fl.img, (j * 50), (i * 50));
	else if (map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, \
			map->pl.i.img, (j * 50), (i * 50));
		if (map->pl.x == 0)
			map->pl.x = j;
		if (map->pl.y == 0)
			map->pl.y = i;
	}
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->end.img, (j * 50), (i * 50));
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->ck.img, (j * 50), (i * 50));
	return ;
}
