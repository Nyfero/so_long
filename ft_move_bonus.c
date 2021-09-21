/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/21 17:32:51 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up_bonus(t_map *map)
{
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
			map->c--;
		if (map->map[map->pl.y][map->pl.x - 1] == 'A')
			ft_end(map);
		map->map[map->pl.y][map->pl.x - 1] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.x -= 1;
		map->mv++;
	}
	return ;
}

void	ft_move_down_bonus(t_map *map)
{
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
			map->c--;
		if (map->map[map->pl.y + 1][map->pl.x] == 'A')
			ft_end(map);
		map->map[map->pl.y + 1][map->pl.x] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.y += 1;
		map->mv++;
	}
}

void	ft_move_left_bonus(t_map *map)
{
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
			map->c--;
		if (map->map[map->pl.y - 1][map->pl.x] == 'A')
			ft_end(map);
		map->map[map->pl.y - 1][map->pl.x] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.y -= 1;
		map->mv++;
	}
}

void	ft_move_right_bonus(t_map *map)
{
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
			map->c--;
		if (map->map[map->pl.y][map->pl.x + 1] == 'A')
			ft_end(map);
		map->map[map->pl.y][map->pl.x + 1] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.x += 1;
		map->mv++;
	}
}
