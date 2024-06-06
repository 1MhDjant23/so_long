/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:19:02 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/06 12:17:18 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	path_valid(t_long *my, int x, int y)
{
	if (my->split[x][y] == '1' || my->split[x][y] == 'X')
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
	path_valid(my, x, y + 1);
	path_valid(my, x, y - 1);
	path_valid(my, x + 1, y);
	path_valid(my, x - 1, y);
}
 
void	find_pos_player(t_long *my)
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
	path_valid(my, my->player_y, my->player_x);
	if ((my->c != my->f_c) || (my->e != my->f_e))
		return (free_mystruct(my));
}

int	check_duplicat(t_long *myStruct)
{
	myStruct->i = 0;
	myStruct->e = 0;
	myStruct->c = 0;
	myStruct->x = 0;
	myStruct->player = 0;
	while (myStruct->map[myStruct->i])
	{
		if (myStruct->map[myStruct->i] == 'C')
			(myStruct->c)++;
		if (myStruct->map[myStruct->i] == 'X')
			(myStruct->x)++;
		if (myStruct->map[myStruct->i] == 'P')
			(myStruct->player)++;
		if (myStruct->map[myStruct->i] == 'E')
			(myStruct->e)++;
		(myStruct->i)++;
	}
	if ((myStruct->e) != 1 || (myStruct->player) != 1 || (myStruct->c) < 1
		|| (myStruct->x) < 1)
		return (-1);
	return (0);
}

void	reading_file(t_long *game, char *av)
{
	char	*temp;

	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
		return (free(game), exit(write(2, "Error\n", 6)));
	game->first_line = get_next_line(game->fd);
	if (line_check(game->first_line) == -1)
		ex_it(&(game->first_line), game, 1);
	game->get_line = get_next_line(game->fd);
	if (!(game->get_line))
		ex_it(&(game->first_line), game, 1);
	game->map = str_copy(game->map, game->first_line);
	if (!(game->map))
		return (free(game->first_line), ex_it(&(game->get_line), game, 1));
	while (game->get_line)
	{
		if (element(game) == -1)
			ex_it(&(game->first_line), game, 2);
		temp = game->map;
		game->map = ft_strjoin(game->map, game->get_line);
		free(game->get_line);
		free(temp);
		game->get_line = get_next_line(game->fd);
		(game->height_c)++;
	}
}

void	map_check(t_long *game, char *av)
{
	game->height_c = 0;
	reading_file(game, av);
	game->last_line = ft_strrchr(game->map, '\n');
	if ((count_char(game->first_line) != count_char(game->last_line))
		|| (line_check(game->last_line) == -1))
		ex_it(&(game->first_line), game, 2);
	if (check_duplicat(game) == -1)
		ex_it(&(game->first_line), game, 2);
	find_pos_player(game);
	free_array(game->split);
}
