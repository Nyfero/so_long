/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/29 18:37:34 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_go_up(t_map *map)
{
	int	i;

	i = 0;
	map->img.path = "./img/player_animation/pl_mv_up_1.xpm";
	while(i++ < 300)
		ft_place_player(map);
	i = 0;
	map->img.path = "./img/player_animation/pl_mv_up_2.xpm";
	while(i++ < 300)
		ft_place_player(map);
	ft_move_up_bonus(map);
}

void	ft_go_down(t_map *map)
{
	int	i;

	i = 0;
	map->img.path = "./img/player_animation/pl_mv_dw_1.xpm";
	while(i++ < 300)
		ft_place_player(map);
	i = 0;
	map->img.path = "./img/player_animation/pl_mv_dw_2.xpm";
	while(i++ < 300)
		ft_place_player(map);
	ft_move_down_bonus(map);
}

void	ft_go_right(t_map *map)
{
	int	i;

	i = 0;
	map->img.path = "./img/player_animation/pl_mv_rg_1.xpm";
	while(i++ < 200)
		ft_place_player(map);
	i = 0;
	map->img.path = "./img/player_animation/pl_mv_rg_2.xpm";
	while(i++ < 200)
		ft_place_player(map);
	i = 0;
	map->img.path = "./img/player_animation/pl_mv_rg_3.xpm";
	while(i++ < 200)
		ft_place_player(map);
	ft_move_right_bonus(map);
}

void	ft_go_left(t_map *map)
{
	int	i;

	i = 0;
	map->img.path = "./img/player_animation/pl_mv_lf_1.xpm";
	while(i++ < 200)
		ft_place_player(map);
	i = 0;
	map->img.path = "./img/player_animation/pl_mv_lf_2.xpm";
	while(i++ < 200)
		ft_place_player(map);
	i = 0;
	map->img.path = "./img/player_animation/pl_mv_lf_3.xpm";
	while(i++ < 200)
		ft_place_player(map);
	ft_move_left_bonus(map);
}
