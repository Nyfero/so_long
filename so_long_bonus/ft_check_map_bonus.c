/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/10/01 14:57:09 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_valid_map(t_map *map, char *file)
{
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->a = 0;
	ft_map_closed(map, file);
	ft_well_composed_bonus(map, file);
	if (map->c == 0 || map->p != 1 || map->e == 0)
		ft_error(4);
	return ;
}

void	ft_map_closed(t_map *map, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	j = 0;
	while (tmp != NULL)
	{
		i = -1;
		if (j == 0 || j == (map->y - 1))
			while (tmp[++i])
				if (tmp[i] != '1')
					ft_error_parsing(2, tmp);
		if (tmp[0] != '1' || tmp[(map->x - 1)] != '1')
			ft_error_parsing(2, tmp);
		free(tmp);
		j++;
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
}

void	ft_well_composed_bonus(t_map *map, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	ft_check_in_map(map, fd);
	close(fd);
}

void	ft_check_in_map(t_map *map, int fd)
{
	int		i;
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		i = -1;
		while (tmp[++i])
		{
			if (tmp[i] != 'C' && tmp[i] != 'E' && tmp[i] != 'P' && tmp[i] != '0'
				&& tmp[i] != '1' && tmp[i] != 'A')
				ft_error_parsing(4, tmp);
			else if (tmp[i] == 'C')
				map->c++;
			else if (tmp[i] == 'P')
				map->p++;
			else if (tmp[i] == 'E')
				map->e++;
			else if (tmp[i] == 'A')
				map->a++;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
}
