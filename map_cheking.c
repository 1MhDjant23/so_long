/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:06:12 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/10 00:47:31 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_path(t_long *my, int x, int y)
{
	if (my->split[x][y] == '1')
		return ;
	else if (my->split[x][y] == 'C')
	{
		(my->f_c)++;
		my->split[x][y] = '1';
	}
	else if (my->split[x][y] == 'E')
	{
		(my->f_e)++;
		my->split[x][y] = '1';
	}
	my->split[x][y] = '1';
	valid_path(my, x, y + 1);
	valid_path(my, x, y - 1);
	valid_path(my, x + 1, y);
	valid_path(my, x - 1, y);
}

void	find_player(t_long *my)
{
	my->f_c = 0;
	my->f_e = 0;
	my->player_y = 0;
	my->player_x = 0;
	my->split = ft_split(my->map, '\n');
	while (my->split[my->player_y])
	{
		my->player_x = ft_strchr(my->split[my->player_y], 'P');
		if (my->player_x != -1)
			break ;
		(my->player_y)++;
	}
	valid_path(my, my->player_y, my->player_x);
	if ((my->c != my->f_c) || (my->e != my->f_e))
		return (free_mystruct(my));
}

int	check_dup_player(t_long *myStruct)
{
	myStruct->i = 0;
	myStruct->e = 0;
	myStruct->c = 0;
	myStruct->player = 0;
	while (myStruct->map[myStruct->i])
	{
		if (myStruct->map[myStruct->i] == 'C')
			(myStruct->c)++;
		if (myStruct->map[myStruct->i] == 'P')
			(myStruct->player)++;
		if (myStruct->map[myStruct->i] == 'E')
			(myStruct->e)++;
		(myStruct->i)++;
	}
	if ((myStruct->e) != 1 || (myStruct->player) != 1 || (myStruct->c) < 1)
		return (-1);
	return (0);
}

void	read_file(t_long *game, char *av)
{
	char	*temp;

	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
		return (ex_it(NULL, game, 5));
	game->first_line = get_next_line(game->fd);
	if (check_line(game->first_line) == -1)
		ex_it(&(game->first_line), game, 1);
	game->get_line = get_next_line(game->fd);
	if (!(game->get_line))
		ex_it(&(game->first_line), game, 1);
	game->map = str_copy(game->map, game->first_line);
	if (!(game->map))
		return (free(game->first_line), ex_it(&(game->get_line), game, 1));
	while (game->get_line)
	{
		if (element_map(game) == -1)
			ex_it(&(game->first_line), game, 2);
		temp = game->map;
		game->map = ft_strjoin(game->map, game->get_line);
		free(game->get_line);
		free(temp);
		game->get_line = get_next_line(game->fd);
		(game->height_c)++;
	}
}

void	checking_map(t_long *game, char *av)
{
	game->height_c = 0;
	read_file(game, av);
	game->last_line = ft_strrchr(game->map, '\n');
	if ((count_char(game->first_line) != count_char(game->last_line))
		|| (check_line(game->last_line) == -1))
		ex_it(&(game->first_line), game, 2);
	if (check_dup_player(game) == -1)
		ex_it(&(game->first_line), game, 2);
	find_player(game);
	close(game->fd);
	free_array(game->split);
}
