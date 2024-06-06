/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:48 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/06 01:27:50 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	g_count_move;

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_long	*my;

	my = (t_long *) param;
	if ((my->c == (my->f_c / 2) && my->split[((my->pl->instances->y) / 60)]
			[(my->pl->instances->x) / 60] == 'E'))
		free_textures(my, 1);
	if (keydata.action == 1 || keydata.action == 2)
	{
		if (keydata.key == 256)
			free_textures(my, -1);
		else if ((keydata.key == 87 || keydata.key == 265) && (my->split[(my
						->pl->instances->y - 60) / 60][(my->pl->instances->x)
				/ 60] != '1'))
			move_player(my, 0, -60);
		else if ((keydata.key == 68 || keydata.key == 262) && (my->split[(my->pl
						->instances->y) / 60][(my->pl->instances->x + 60) / 60]
			!= '1'))
			move_player(my, 60, 0);
		else if ((keydata.key == 83 || keydata.key == 264) && (my->split[(my->pl
						->instances->y + 60) / 60][(my->pl->instances->x) / 60]
			!= '1'))
			move_player(my, 0, 60);
		else if (keydata.key == 65 || keydata.key == 263)
			move_player(my, -60, 0);
	}
}

void	count_collectible(t_long *st, int mx, int my)
{
	if ((mx == 0 && my == -60) && (st->split[(st->pl->instances->y - 60) / 60]
			[(st->pl->instances->x) / 60] == 'C'))
		(st->f_c)++;
	else if ((mx == 0 && my == 60) && (st->split[(st->pl->instances->y + 60)
				/ 60][(st->pl->instances->x) / 60] == 'C'))
		(st->f_c)++;
	else if ((mx == 60 && my == 0) && (st->split[(st->pl->instances->y) / 60]
			[(st->pl->instances->x + 60) / 60] == 'C'))
		(st->f_c)++;
	else if ((mx == -60 && my == 0) && (st->split[(st->pl->instances->y) / 60]
			[(st->pl->instances->x - 60) / 60] == 'C'))
		(st->f_c)++;
	if (st->split[((st->pl->instances->y) / 60)][(st->pl->instances->x)
		/ 60] != 'E')
	{
		mlx_image_to_window(st->x42, st->load_layer, st->pl->instances
			->x, st->pl->instances->y);
		st->split[(st->pl->instances->y) / 60][(st->pl->instances->x)
			/ 60] = '0';
	}
}

void	move_player(t_long *st, int mx, int my)
{
	if ((mx == -60 && my == 0) && (st->split[(st->pl->instances->y) / 60]
			[(st->pl->instances->x - 60) / 60] == '1'))
		return ;
	g_count_move++;
	ft_printf("%d move\n", g_count_move);
	count_collectible(st, mx, my);
	st->pl->instances->x += mx;
	st->pl->instances->y += my;
	if (st->c == (st->f_c) / 2)
	{
		mlx_delete_image(st->x42, st->load_exit);
		mlx_image_to_window(st->x42, st->load_exit1, st->exit_px * 60,
			st->exit_py * 60);
	}
	if (st->split[((st->pl->instances->y) / 60)][(st->pl->instances->x)
		/ 60] != 'E')
	{
		mlx_image_to_window(st->x42, st->load_layer, st->pl->instances->x,
			st->pl->instances->y);
		mlx_image_to_window(st->x42, st->pl, st->pl->instances->x, st->pl
			->instances->y);
	}
}

void	close_widget(void *param)
{
	t_long	*game;

	game = (t_long *)param;
	if (game->first_line)
		free(game->first_line);
	if (game->split)
		free_array(game->split);
	if (game->map)
		free(game->map);
	if (game->layer)
		mlx_delete_texture(game->layer);
	if (game->exit)
		mlx_delete_texture(game->exit);
	if (game->exit1)
		mlx_delete_texture(game->exit1);
	if (game->coin)
		mlx_delete_texture(game->coin);
	if (game->wall)
		mlx_delete_texture(game->wall);
	if (game->pl_right)
		mlx_delete_texture(game->pl_right);
	mlx_close_window(game->x42);
	exit(write(1, "EXIT\n", 5));
}
