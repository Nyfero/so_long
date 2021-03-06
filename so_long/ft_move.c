/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 13:23:37 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_map *map)
{
	if (map->map[map->pl.y - 1][map->pl.x] != '1')
	{
		if (map->map[map->pl.y - 1][map->pl.x] == 'E')
		{
			if (map->c == 0)
				ft_win(map);
			else
				return ;
		}
		if (map->map[map->pl.y - 1][map->pl.x] == 'C')
			map->c--;
		map->map[map->pl.y - 1][map->pl.x] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.y -= 1;
		ft_putstr("Number of move :");
		ft_putnbr(++map->mv);
		ft_putchar('\n');
	}
	return ;
}

void	ft_move_down(t_map *map)
{
	if (map->map[map->pl.y + 1][map->pl.x] != '1')
	{
		if (map->map[map->pl.y + 1][map->pl.x] == 'E')
		{
			if (map->c == 0)
				ft_win(map);
			else
				return ;
		}
		if (map->map[map->pl.y + 1][map->pl.x] == 'C')
			map->c--;
		map->map[map->pl.y + 1][map->pl.x] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.y += 1;
		ft_putstr("Number of move :");
		ft_putnbr(++map->mv);
		ft_putchar('\n');
	}
	return ;
}

void	ft_move_left(t_map *map)
{
	if (map->map[map->pl.y][map->pl.x - 1] != '1')
	{
		if (map->map[map->pl.y][map->pl.x - 1] == 'E')
		{
			if (map->c == 0)
				ft_win(map);
			else
				return ;
		}
		if (map->map[map->pl.y][map->pl.x - 1] == 'C')
			map->c--;
		map->map[map->pl.y][map->pl.x - 1] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.x -= 1;
		ft_putstr("Number of move :");
		ft_putnbr(++map->mv);
		ft_putchar('\n');
	}
	return ;
}

void	ft_move_right(t_map *map)
{
	if (map->map[map->pl.y][map->pl.x + 1] != '1')
	{
		if (map->map[map->pl.y][map->pl.x + 1] == 'E')
		{
			if (map->c == 0)
				ft_win(map);
			else
				return ;
		}
		if (map->map[map->pl.y][map->pl.x + 1] == 'C')
			map->c--;
		map->map[map->pl.y][map->pl.x + 1] = 'P';
		map->map[map->pl.y][map->pl.x] = '0';
		map->pl.x += 1;
		ft_putstr("Number of move :");
		ft_putnbr(++map->mv);
		ft_putchar('\n');
	}
	return ;
}
