/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ennemie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/10/01 14:59:31 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_ennemie(t_map *map)
{
	int	i;

	i = -1;
	while (++i < (int)map->a)
	{
		if (map->enm[i].lm == 0)
			ft_enm_up(map, i);
		if (map->enm[i].lm == 1)
			ft_enm_left(map, i);
		if (map->enm[i].lm == 2)
			ft_enm_down(map, i);
		if (map->enm[i].lm == 3)
		{
			ft_enm_right(map, i);
			map->enm[i].lm -= 4;
		}
		map->enm[i].lm++;
		if (map->enm[i].x == map->pl.x && map->enm[i].y == map->pl.y)
			ft_loose(map, i);
	}
}

void	ft_enm_up(t_map *map, int i)
{
	int	j;

	j = -1;
	if (map->map[map->enm[i].y - 1][map->enm[i].x] != '1'
		&& map->map[map->enm[i].y - 1][map->enm[i].x] != 'E')
	{
		while (++j < (int)map->a)
			if (map->enm[i].x == map->enm[j].x
				&& map->enm[i].y - 1 == map->enm[j].y)
				return ;
		map->enm[i].y -= 1;
	}
	return ;
}

void	ft_enm_down(t_map *map, int i)
{
	int	j;

	j = -1;
	if (map->map[map->enm[i].y + 1][map->enm[i].x] != '1'
		&& map->map[map->enm[i].y + 1][map->enm[i].x] != 'E')
	{
		while (++j < (int)map->a)
			if (map->enm[i].x == map->enm[j].x
				&& map->enm[i].y + 1 == map->enm[j].y)
				return ;
		map->enm[i].y += 1;
	}
	return ;
}

void	ft_enm_left(t_map *map, int i)
{
	int	j;

	j = -1;
	if (map->map[map->enm[i].y][map->enm[i].x - 1] != '1'
		&& map->map[map->enm[i].y][map->enm[i].x - 1] != 'E')
	{
		while (++j < (int)map->a)
			if (map->enm[i].x - 1 == map->enm[j].x
				&& map->enm[i].y == map->enm[j].y)
				return ;
		map->enm[i].x -= 1;
	}
	return ;
}

void	ft_enm_right(t_map *map, int i)
{
	int	j;

	j = -1;
	if (map->map[map->enm[i].y][map->enm[i].x + 1] != '1'
		&& map->map[map->enm[i].y][map->enm[i].x + 1] != 'E')
	{
		while (++j < (int)map->a)
			if (map->enm[i].x + 1 == map->enm[j].x
				&& map->enm[i].y == map->enm[j].y)
				return ;
		map->enm[i].x += 1;
	}
	return ;
}
