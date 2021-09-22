/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/22 14:24:25 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_multiple_frame(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < 2147483647 / 4)
	{
		if (i == 2147483647 / 4)
		{
			i = 0;
			ft_switch_posture(map);
		}
	}
}

void	ft_switch_posture(t_map *map)
{
	if (map->pl.p == 0)
	{
		map->img.path = "./img/player_animation/pl_fc.xpm";
		map->img.img = mlx_xpm_file_to_image(map->mlx, map->img.path, \
			&map->img.width, &map->img.height);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, \
			(map->pl.x * 50), (map->pl.y * 50));
		map->pl.p++;
	}
	else
	{
		map->img.path = "./img/Player.xpm";
		map->img.img = mlx_xpm_file_to_image(map->mlx, map->img.path, \
			&map->img.width, &map->img.height);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, \
			(map->pl.x * 50), (map->pl.y * 50));
		map->pl.p--;
	}
}
