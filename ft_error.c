/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:09:25 by gsap              #+#    #+#             */
/*   Updated: 2021/09/16 17:30:20 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int err)
{
	write(2, "Error\n", 5);
	if (err == 1)
		write(2, "No file submited\n", 17);
	else if (err == 2)
		write(2, "Too many files\n", 15);
	else if (err == 3)
		write(2, "Unvalid file\n", 13);
	exit(1);
}

void 	ft_error_parsing(int err)
{
	write(2, "Error\n", 6);
	if (err == 1)
		write(2, "Map isn't rectangular\n", 22);
	else if (err == 2)
		write(2, "The map isn't closed\n", 21);
	else if (err == 3)
		write(2, "File isn't in \".ber\" format\n", 28);
	else if (err == 4)
	{
		write(2, "The map must have at least one exit, one collectible,", 53);
		write(2, " and only one starting position\n", 32);
	}
	else if (err == 5)
		write(2, "Character(s) not allowed\n", 25);
	exit(1);
}
