/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:32:27 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/10 00:49:19 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	element_map(t_long *game)
{
	game->i = 0;
	if (count_char(game->first_line) != count_char(game->get_line))
		return (-1);
	if (game->get_line[0] != '1' || game->get_line[count_char(game
				->first_line) - 1] != '1')
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
	if (count_char(av) == 4 || (ft_memcmp(av, "maps/.ber", 9) == 0))
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

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void	ex_it(char **str, t_long *game, int x)
{
	if (x == 5)
	{
		free(game);
		ft_printf("Error\n");
		ft_printf("IV file\n");
		exit(1);
	}
	if (x == 1)
	{
		free(*str);
		close(game->fd);
		free(game);
		ft_printf("Error\n");
		exit(write(2, "IV map\n", 7));
	}
	if (x == 2)
	{
		free(*str);
		free(game->get_line);
		free(game->map);
		close(game->fd);
		free(game);
		ft_printf("Error\n");
		exit(write(2, "IV map\n", 7));
	}
}
