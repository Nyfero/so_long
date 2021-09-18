/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/18 17:26:03 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display(t_map *map)
{
	t_img	img;

	img.img = mlx_new_image(map->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpb, &img.ll, &img.end);
	
}
