/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 17:27:20 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_img(t_map *map)
{
	ft_init_player_anm(map);
	ft_init_rest(map);
	if (map->pl.i.img == NULL || map->fl.img == NULL || map->wl.img == NULL
		|| map->ck.img == NULL || map->end.img == NULL
		|| map->pl.md1.img == NULL || map->pl.md2.img == NULL
		|| map->pl.mu1.img == NULL || map->pl.mu2.img == NULL
		|| map->pl.ml1.img == NULL || map->pl.ml2.img == NULL
		|| map->pl.ml3.img == NULL || map->pl.mr1.img == NULL
		|| map->pl.mr2.img == NULL || map->pl.mr3.img == NULL
		|| map->pl.dd1.img == NULL || map->pl.dd2.img == NULL
		|| map->ie.n.img == NULL || map->ie.e.img == NULL)
	{
		ft_free_img(map);
		ft_free_ls(map->map);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		ft_error(3);
	}
}

void	ft_init_player_anm(t_map *map)
{
	map->pl.md1.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_dw_1.xpm", &map->pl.md1.width, &map->pl.md1.height);
	map->pl.md2.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_dw_2.xpm", &map->pl.md2.width, &map->pl.md2.height);
	map->pl.mu1.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_up_1.xpm", &map->pl.mu1.width, &map->pl.mu1.height);
	map->pl.mu2.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_up_2.xpm", &map->pl.mu2.width, &map->pl.mu2.height);
	map->pl.ml1.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_lf_1.xpm", &map->pl.ml1.width, &map->pl.ml1.height);
	map->pl.ml2.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_lf_2.xpm", &map->pl.ml2.width, &map->pl.ml2.height);
	map->pl.ml3.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_lf_3.xpm", &map->pl.ml3.width, &map->pl.ml3.height);
	map->pl.mr1.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_rg_1.xpm", &map->pl.mr1.width, &map->pl.mr1.height);
	map->pl.mr2.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_rg_2.xpm", &map->pl.mr2.width, &map->pl.mr2.height);
	map->pl.mr3.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_mv_rg_3.xpm", &map->pl.mr3.width, &map->pl.mr3.height);
	map->pl.dd1.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_dd_1.xpm", &map->pl.dd1.width, &map->pl.dd1.height);
	map->pl.dd2.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/pl_anm/pl_dd_2.xpm", &map->pl.dd2.width, &map->pl.dd2.height);
}

void	ft_init_rest(t_map *map)
{
	map->fl.img = mlx_xpm_file_to_image(map->mlx, "./img/Grass.xpm", \
	&map->fl.width, &map->fl.height);
	map->wl.img = mlx_xpm_file_to_image(map->mlx, "./img/Wall.xpm", \
	&map->wl.width, &map->wl.height);
	map->ck.img = mlx_xpm_file_to_image(map->mlx, "./img/Cookie.xpm", \
	&map->ck.width, &map->ck.height);
	map->end.img = mlx_xpm_file_to_image(map->mlx, "./img/End.xpm", \
	&map->end.width, &map->end.height);
	map->pl.i.img = mlx_xpm_file_to_image(map->mlx, "./img/Player.xpm", \
	&map->pl.i.width, &map->pl.i.height);
	map->ie.n.img = mlx_xpm_file_to_image(map->mlx, "./img/Ennemie.xpm", \
	&map->ie.n.width, &map->ie.n.height);
	map->ie.e.img = mlx_xpm_file_to_image(map->mlx, \
	"./img/Ennemie_explode.xpm", &map->ie.e.width, &map->ie.e.height);
}

void	ft_free_img(t_map *map)
{
	if (map->fl.img != NULL)
		mlx_destroy_image(map->mlx, map->fl.img);
	if (map->wl.img != NULL)
		mlx_destroy_image(map->mlx, map->wl.img);
	if (map->ck.img != NULL)
		mlx_destroy_image(map->mlx, map->ck.img);
	if (map->end.img != NULL)
		mlx_destroy_image(map->mlx, map->end.img);
	if (map->pl.i.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.i.img);
	if (map->ie.n.img != NULL)
		mlx_destroy_image(map->mlx, map->ie.n.img);
	if (map->ie.e.img != NULL)
		mlx_destroy_image(map->mlx, map->ie.e.img);
	if (map->pl.mr1.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.mr1.img);
	if (map->pl.mr2.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.mr2.img);
	if (map->pl.mr3.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.mr3.img);
	if (map->pl.dd1.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.dd1.img);
	if (map->pl.dd2.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.dd2.img);
	ft_more_free_img(map);
}

void	ft_more_free_img(t_map *map)
{
	if (map->pl.ml1.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.ml1.img);
	if (map->pl.ml2.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.ml2.img);
	if (map->pl.ml3.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.ml3.img);
	if (map->pl.mu1.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.mu1.img);
	if (map->pl.mu2.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.mu2.img);
	if (map->pl.md1.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.md1.img);
	if (map->pl.md2.img != NULL)
		mlx_destroy_image(map->mlx, map->pl.md2.img);
	return ;
}
