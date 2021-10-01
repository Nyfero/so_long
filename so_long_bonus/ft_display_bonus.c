/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/10/01 14:57:44 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_display_bonus(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			ft_pick_image_bonus(map, i, j);
	}
	mlx_put_image_to_window(map->mlx, map->win, \
		map->pl.i.img, (map->pl.x * 50), (map->pl.y * 50));
	ft_place_ennemie(map);
	ft_compt_bonus(map);
	return (0);
}

void	ft_place_player(t_map *map, t_img player)
{
	mlx_put_image_to_window(map->mlx, map->win, \
		player.img, (map->pl.x * 50), (map->pl.y * 50));
	return ;
}

void	ft_place_ennemie(t_map *map)
{
	int	tmp;

	tmp = 0;
	while (tmp < (int)map->a)
	{
		mlx_put_image_to_window(map->mlx, map->win, \
			map->ie.n.img, (map->enm[tmp].x * 50), (map->enm[tmp].y * 50));
		tmp++;
	}
	return ;
}

void	ft_pick_image_bonus(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->wl.img, (j * 50), (i * 50));
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->fl.img, (j * 50), (i * 50));
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->end.img, (j * 50), (i * 50));
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->ck.img, (j * 50), (i * 50));
	return ;
}

void	ft_compt_bonus(t_map *map)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_itoa(map->mv);
	tmp = ft_strjoin("Nmb of move : ", tmp2);
	free(tmp2);
	mlx_string_put(map->mlx, map->win, 10, 20, 0X0FFFFFF, tmp);
	free(tmp);
	if (map->c > 0)
	{
		tmp2 = ft_itoa(map->c);
		tmp = ft_strjoin("Cookie(s) remaining : ", tmp2);
		free(tmp2);
		mlx_string_put(map->mlx, map->win, 10, 40, 0X0FFFFFF, tmp);
		free(tmp);
	}
	else
		mlx_string_put(map->mlx, map->win, 10, 40, 0X0FFFFFF, "Go finish !");
	return ;
}
