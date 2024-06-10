/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:01:53 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/08 11:48:13 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_textures(t_long *mystruct, int x)
{
	mlx_delete_texture(mystruct->layer);
	mlx_delete_texture(mystruct->exit1);
	mlx_delete_texture(mystruct->coin);
	mlx_delete_texture(mystruct->wall);
	mlx_delete_texture(mystruct->ghost);
	mlx_delete_texture(mystruct->enemy);
	free_array(mystruct->split);
	mlx_close_window(mystruct->x42);
	free(mystruct->x42);
	if (x == 1)
		print_win();
	if (x == -1)
		exit(write(1, "EXIT\n", 5));
	if (x == 5)
		print_wast();
}

void	faill_textures(t_long *mystruct, int f)
{
	if (f != 0)
	{
		if (mystruct->layer && (f == 1 || f == 2 || f == 3 || f == 4 || f == 5
				|| f == 6))
			mlx_delete_texture(mystruct->layer);
		if (mystruct->ghost && (f == 2 || f == 3 || f == 4 || f == 5 || f == 6))
			mlx_delete_texture(mystruct->ghost);
		if (mystruct->coin && (f == 3 || f == 4 || f == 5 || f == 6))
			mlx_delete_texture(mystruct->coin);
		if (mystruct->wall && (f == 4 || f == 5 || f == 6))
			mlx_delete_texture(mystruct->wall);
		if (mystruct->exit && (f == 5 || f == 6))
			mlx_delete_texture(mystruct->exit);
		if (mystruct->exit1 && f == 6)
			mlx_delete_texture(mystruct->exit1);
	}
	if (mystruct->split)
		free_array(mystruct->split);
	mlx_close_window(mystruct->x42);
	exit(write(2, "PNG NOT FOUND\n", 14));
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

void	free_mystruct(t_long *mystruct)
{
	int	n;

	n = 0;
	if (mystruct->split)
	{
		while (mystruct->split[n])
			free(mystruct->split[n++]);
		free(mystruct->split);
	}
	if (mystruct->map)
		free(mystruct->map);
	if (mystruct->first_line)
		free(mystruct->first_line);
	if (mystruct->get_line)
		free(mystruct->get_line);
	close(mystruct->fd);
	if (mystruct)
		free(mystruct);
	ft_printf("Error\n");
	exit(write(2, "IV PATH\n", 8));
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
