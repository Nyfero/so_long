/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/29 15:46:51 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing_bonus(t_map *map, char *file)
{
	ft_map_size(map, file);
	ft_check_valid_map(map, file);
	map->map = (char **)malloc(sizeof(char *) * (map->y + 1));
	if (!map->map)
		ft_error(0);
	map->map[map->y] = 0;
	map->enm = (t_enm *)malloc(sizeof(t_enm) * (map->a + 1));
	if (!map->enm)
		ft_error(0);
	map->e = map->a - 1;
	ft_create_map(map, file);
}

void	ft_create_map(t_map *map, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp != NULL)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->x + 1));
		if (!map->map[i])
		{
			ft_free_ls(map->map);
			ft_error(0);
		}
		j = -1;
		while (tmp[++j])
			ft_save_map_bonus(map, i, j, tmp);
		map->map[i][j] = 0;
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	ft_save_map_bonus(t_map *map, int i, int j, char *tmp)
{
	if (tmp[j] != 'P' && tmp[j] != 'A')
		map->map[i][j] = tmp[j];
	else
	{
		map->map[i][j] = '0';
		if (tmp[j] == 'P')
		{
			map->pl.x = j;
			map->pl.y = i;
		}
		else
		{
			map->enm[map->e].x = j;
			map->enm[map->e--].y = i;
		}
	}
	return ;
}
