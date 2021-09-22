/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/22 14:15:12 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display_bonus(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			ft_pick_image_bonus(map, i, j);
			map->img.img = mlx_xpm_file_to_image(map->mlx, map->img.path, \
				&map->img.width, &map->img.height);
			if (map->img.img == NULL)
				ft_error(3);
			mlx_put_image_to_window(map->mlx, map->win, \
				map->img.img, (j * 50), (i * 50));
		}
	}
	ft_compt_bonus(map);
	return (0);
}

void	ft_pick_image_bonus(t_map *map, int i, int j)
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
		map->pl.p = 0;
	}
	else if (map->map[i][j] == 'E')
		map->img.path = "./img/End.xpm";
	else if (map->map[i][j] == 'C')
		map->img.path = "./img/Cookie.xpm";
	else if (map->map[i][j] == 'A')
		map->img.path = "./img/Ennemie.xpm";
	return ;
}

void	ft_compt_bonus(t_map *map)
{
	char	*tmp;

	tmp = ft_strjoin("Nmb of move : ", ft_itoa(map->mv));
	mlx_string_put(map->mlx, map->win, 10, 20, 0X0FFFFFF, tmp);
	free(tmp);
	if (map->c > 0)
	{
		tmp = ft_strjoin("Cookie(s) remaining : ", ft_itoa(map->c));
		mlx_string_put(map->mlx, map->win, 10, 40, 0X0FFFFFF, tmp);
		free(tmp);
	}
	else
		mlx_string_put(map->mlx, map->win, 10, 40, 0X0FFFFFF, "Go finish !");
	return ;
}
