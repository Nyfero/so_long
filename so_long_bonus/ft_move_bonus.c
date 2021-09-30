/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 16:24:36 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_up_bonus(t_map *map)
{
	int	tmp;

	if (map->map[map->pl.y - 1][map->pl.x] != '1')
	{
		if (map->map[map->pl.y - 1][map->pl.x] == 'E')
		{
			if (map->c == 0)
				ft_win_bonus(map);
			else
				return ;
		}
		if (map->map[map->pl.y - 1][map->pl.x] == 'C')
		{
			map->map[map->pl.y - 1][map->pl.x] = '0';
			map->c--;
		}
		tmp = -1;
		while (++tmp < (int)map->a)
			if ((map->pl.y - 1 == map->enm[tmp].y)
				&& (map->pl.x == map->enm[tmp].x))
				ft_loose(map, tmp);
		map->pl.y -= 1;
		map->mv++;
	}
}

void	ft_move_down_bonus(t_map *map)
{
	int	tmp;

	if (map->map[map->pl.y + 1][map->pl.x] != '1')
	{
		if (map->map[map->pl.y + 1][map->pl.x] == 'E')
		{
			if (map->c == 0)
				ft_win_bonus(map);
			else
				return ;
		}
		if (map->map[map->pl.y + 1][map->pl.x] == 'C')
		{
			map->c--;
			map->map[map->pl.y + 1][map->pl.x] = '0';
		}
		tmp = -1;
		while (++tmp < (int)map->a)
			if ((map->pl.y + 1 == map->enm[tmp].y)
				&& (map->pl.x == map->enm[tmp].x))
				ft_loose(map, tmp);
		map->pl.y += 1;
		map->mv++;
	}
}

void	ft_move_left_bonus(t_map *map)
{
	int	tmp;

	if (map->map[map->pl.y][map->pl.x - 1] != '1')
	{
		if (map->map[map->pl.y][map->pl.x - 1] == 'E')
		{
			if (map->c == 0)
				ft_win_bonus(map);
			else
				return ;
		}
		if (map->map[map->pl.y][map->pl.x - 1] == 'C')
		{
			map->c--;
			map->map[map->pl.y][map->pl.x - 1] = '0';
		}
		tmp = -1;
		while (++tmp < (int)map->a)
			if ((map->pl.y == map->enm[tmp].y)
				&& (map->pl.x - 1 == map->enm[tmp].x))
				ft_loose(map, tmp);
		map->pl.x -= 1;
		map->mv++;
	}
}

void	ft_move_right_bonus(t_map *map)
{
	int	tmp;

	if (map->map[map->pl.y][map->pl.x + 1] != '1')
	{
		if (map->map[map->pl.y][map->pl.x + 1] == 'E')
		{
			if (map->c == 0)
				ft_win_bonus(map);
			else
				return ;
		}
		if (map->map[map->pl.y][map->pl.x + 1] == 'C')
		{
			map->c--;
			map->map[map->pl.y][map->pl.x + 1] = '0';
		}
		tmp = -1;
		while (++tmp < (int)map->a)
			if ((map->pl.y == map->enm[tmp].y)
				&& (map->pl.x + 1 == map->enm[tmp].x))
				ft_loose(map, tmp);
		map->pl.x += 1;
		map->mv++;
	}
}
