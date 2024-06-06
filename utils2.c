/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:32:27 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/06 11:30:45 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	element_map(t_long *game)
{
	game->i = 0;
	if (count_char(game->first_line) != count_char(game->get_line))
		return (-1);
	while (game->get_line[game->i] && game->get_line[game->i] != '\n')
	{
		if (game->get_line[game->i] != '1' && game->get_line[game->i] != 'C'
			&& game->get_line[game->i] != 'E'
			&& game->get_line[game->i] != '0' && game->get_line[game->i] != 'P')
			return (-1);
		(game->i)++;
	}
	return (0);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL || line[0] == '\n')
		return (-1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' || line[i] == ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	check_extension(char *av)
{
	int	i;

	i = 0;
	if (count_char(av) <= 9)
		return (-1);
	while (av[i])
	{
		if (count_char(&(av[i])) == 4)
		{
			if (ft_memcmp(&(av[i]), ".ber", 4) == 0)
				return (0);
		}
		i++;
	}
	return (-1);
}
