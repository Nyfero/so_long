/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/10/01 14:58:12 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_go_up(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < 4000)
		ft_place_player(map, map->pl.mu1);
	i = 0;
	while (i++ < 4000)
		ft_place_player(map, map->pl.mu2);
	ft_move_up_bonus(map);
}

void	ft_go_down(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < 4000)
		ft_place_player(map, map->pl.md1);
	i = 0;
	while (i++ < 4000)
		ft_place_player(map, map->pl.md2);
	ft_move_down_bonus(map);
}

void	ft_go_right(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < 2750)
		ft_place_player(map, map->pl.mr1);
	i = 0;
	while (i++ < 2750)
		ft_place_player(map, map->pl.mr2);
	i = 0;
	while (i++ < 2750)
		ft_place_player(map, map->pl.mr3);
	ft_move_right_bonus(map);
}

void	ft_go_left(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < 2750)
		ft_place_player(map, map->pl.ml1);
	i = 0;
	while (i++ < 2750)
		ft_place_player(map, map->pl.ml2);
	i = 0;
	while (i++ < 2750)
		ft_place_player(map, map->pl.ml3);
	ft_move_left_bonus(map);
}
