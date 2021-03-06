/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/30 13:16:02 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(t_map *map, char *file)
{
	int		fd;
	char	*tmp;

	ft_check_file(file);
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		ft_error(3);
	map->y = 0;
	map->x = ft_strlen(tmp);
	while (tmp != NULL)
	{
		map->y++;
		if (map->x != (int)ft_strlen(tmp))
			ft_error_parsing(1, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
}

void	ft_check_file(char *file)
{
	char	*tmp;

	tmp = ft_substr(file, (ft_strlen(file) - 4), 5);
	if (ft_strncmp(tmp, ".ber", 5) != 0)
		ft_error_parsing(3, tmp);
	free(tmp);
	return ;
}

void	ft_check_valid_map(t_map *map, char *file)
{
	int	fd;

	map->c = 0;
	map->p = 0;
	map->e = 0;
	ft_map_closed(map, file);
	fd = open(file, O_RDONLY);
	ft_well_composed(map, fd);
	close(fd);
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

void	ft_well_composed(t_map *map, int fd)
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
				&& tmp[i] != '1')
				ft_error_parsing(4, tmp);
			else if (tmp[i] == 'C')
				map->c++;
			else if (tmp[i] == 'P')
				map->p++;
			else if (tmp[i] == 'E')
				map->e++;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
}
