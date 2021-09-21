/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/21 16:22:40 by gsap             ###   ########.fr       */
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
		{
			ft_pick_image(map, i, j);
			map->img.img = mlx_xpm_file_to_image(map->mlx, map->img.path, \
				&map->img.width, &map->img.height);
			if (map->img.img == NULL)
				ft_error(3);
			mlx_put_image_to_window(map->mlx, map->win, \
				map->img.img, (j * 50), (i * 50));
		}
	}
	return (0);
}

void	ft_pick_image(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		map->img.path = "./img/Wall.xpm";
	else if (map->map[i][j] == '0')
		map->img.path = "./img/Grass.xpm";
	else if (map->map[i][j] == 'P')
	{
		map->img.path = "./img/Player.xpm";
		if (map->pl.x == 0)
			map->pl.x = j;
		if (map->pl.y == 0)
			map->pl.y = i;
	}
	else if (map->map[i][j] == 'E')
		map->img.path = "./img/End.xpm";
	else if (map->map[i][j] == 'C')
		map->img.path = "./img/Cookie.xpm";
	return ;
}
