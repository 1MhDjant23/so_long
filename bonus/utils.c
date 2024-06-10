/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:00:17 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/10 00:49:39 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_char(char *s)
{
	int	y;

	y = 0;
	while (s[y] && s[y] != '\n')
	{
		y++;
	}
	return (y);
}

int	element(t_long *game)
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
			&& game->get_line[game->i] != 'E' && game->get_line[game->i] != 'X'
			&& game->get_line[game->i] != '0' && game->get_line[game->i] != 'P')
			return (-1);
		(game->i)++;
	}
	return (0);
}

int	line_check(char *line)
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

char	*str_copy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	dst = malloc(sizeof(char ) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	put_count_move(t_long *game, int count)
{
	if (game->moves)
		mlx_delete_image(game->x42, game->moves);
	game->map = ft_itoa(count);
	game->get_line = game->map;
	game->map = ft_strjoin(game->map, " moves");
	free(game->get_line);
	game->moves = mlx_put_string(game->x42, game->map, 15, 15);
	free(game->map);
}
