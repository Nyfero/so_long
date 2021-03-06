/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 14:17:39 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing(t_map *map, char *file)
{
	ft_map_size(map, file);
	ft_check_valid_map(map, file);
	map->map = (char **)malloc(sizeof(char *) * (map->y + 1));
	if (!map->map)
		ft_error(0);
	map->map[map->y] = 0;
	ft_save_map(map, file);
}

void	ft_save_map(t_map *map, char *file)
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
			ft_error_parsing(0, tmp);
		}
		j = -1;
		while (tmp[++j])
			map->map[i][j] = tmp[j];
		map->map[i][j] = 0;
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
}
