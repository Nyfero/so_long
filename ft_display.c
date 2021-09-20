/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/20 16:36:57 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display(t_map *map)
{
	t_img	img;
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '1')
				img.path = "./img/Wall.xpm";
			else if (map->map[i][j] == '0')
				img.path = "./img/Grass.xpm";
			else if (map->map[i][j] == 'P')
			{
				img.path = "./img/Player.xpm";
				map->pl.x = j;
				map->pl.y = i;
			}
			else if (map->map[i][j] == 'E')
				img.path = "./img/End.xpm";
			else if (map->map[i][j] == 'C')
				img.path = "./img/Cookie.xpm";
			img.img = mlx_xpm_file_to_image(map->mlx, img.path, &img.wid, &img.hei);
			if (img.img == NULL)
				ft_error(3);
			mlx_put_image_to_window(map->mlx, map->win, img.img, (i * 50), (j * 50));
		}
	}
}
