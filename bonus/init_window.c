/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:42:30 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/09 23:01:14 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	window_init(t_long *my_struct)
{
	my_struct->x42 = mlx_init((ft_strlen(my_struct->first_line) - 1) * 60,
			(my_struct->height_c + 1) * 60, "GAME", true);
	if (my_struct->x42 == NULL)
		ex_it(&(my_struct->first_line), my_struct, 2);
	free(my_struct->first_line);
	mlx_key_hook(my_struct->x42, &my_keyhook, my_struct);
	my_struct->split = ft_split(my_struct->map, '\n');
	if (!(my_struct->split))
		ex_it(&(my_struct->first_line), my_struct, 2);
	free(my_struct->map);
	load_img(my_struct, my_struct->x42);
	first_layer(my_struct, my_struct->x42);
	second_layer(my_struct, my_struct->x42);
	mlx_close_hook(my_struct->x42, close_widget, my_struct);
	mlx_loop(my_struct->x42);
	mlx_terminate(my_struct->x42);
}

void	second_layer(t_long *st, mlx_t *X42)
{
	st->i = 0;
	while (st->split[st->i])
	{
		st->s = 0;
		while (st->split[st->i][st->s])
		{
			if (st->split[st->i][st->s] == 'C')
				mlx_image_to_window(X42, st->collect, st->s * 60, st->i * 60);
			else if (st->split[st->i][st->s] == 'X')
				mlx_image_to_window(X42, st->load_x, st->s * 60, st->i * 60);
			else if (st->split[st->i][st->s] == 'P')
			{
				st->player_x = st->i;
				st->player_y = st->s;
			}
			(st->s)++;
		}
		(st->i)++;
	}
	mlx_image_to_window(X42, st->pl, (st->player_y) * 60, (st->player_x) * 60);
}

void	first_layer(t_long *st, mlx_t *X42)
{
	st->i = 0;
	while (st->split[st->i])
	{
		st->s = 0;
		while (st->split[st->i][st->s])
		{
			mlx_image_to_window(X42, st->load_layer, st->s * 60, st->i * 60);
			if (st->split[st->i][st->s] == '1')
				mlx_image_to_window(X42, st->load_wall, (st->s) * 60,
					st->i * 60);
			if (st->split[st->i][st->s] == 'E')
			{
				mlx_image_to_window(X42, st->load_exit, st->s * 60, st->i * 60);
				st->exit_py = st->i;
				st->exit_px = st->s;
			}
			(st->s)++;
		}
		(st->i)++;
	}
}

void	load_texture(t_long *mystruct)
{
	mystruct->i = 0;
	mystruct->exit_px = 0;
	mystruct->exit_py = 0;
	mystruct->layer = mlx_load_png("./textures/wall.png");
	if (!(mystruct->layer))
		faill_textures(mystruct, 0);
	mystruct->ghost = mlx_load_png("./textures/player.png");
	if (!(mystruct->ghost))
		faill_textures(mystruct, 1);
	mystruct->coin = mlx_load_png("./textures/coin.png");
	if (!(mystruct->coin))
		faill_textures(mystruct, 1);
	mystruct->wall = mlx_load_png("./textures/tree.png");
	if (!(mystruct->wall))
		faill_textures(mystruct, 3);
	mystruct->exit = mlx_load_png("./textures/door.png");
	if (!(mystruct->exit))
		faill_textures(mystruct, 4);
	mystruct->exit1 = mlx_load_png("./textures/door1.png");
	if (!(mystruct->exit1))
		faill_textures(mystruct, 5);
	mystruct->enemy = mlx_load_png("./textures/enemy.png");
	if (!(mystruct->enemy))
		faill_textures(mystruct, 6);
}

void	load_img(t_long *mystruct, mlx_t *x42)
{
	load_texture(mystruct);
	mystruct->load_layer = mlx_texture_to_image(x42, mystruct->layer);
	if (!(mystruct->load_layer))
		faill_textures(mystruct, 0);
	mystruct->pl = mlx_texture_to_image(x42, mystruct->ghost);
	if (!(mystruct->pl))
		faill_textures(mystruct, 1);
	mystruct->collect = mlx_texture_to_image(x42, mystruct->coin);
	if (!(mystruct->collect))
		faill_textures(mystruct, 2);
	mystruct->load_wall = mlx_texture_to_image(x42, mystruct->wall);
	if (!(mystruct->load_wall))
		faill_textures(mystruct, 3);
	mystruct->load_exit = mlx_texture_to_image(x42, mystruct->exit);
	if (!(mystruct->load_exit))
		faill_textures(mystruct, 4);
	mystruct->load_exit1 = mlx_texture_to_image(x42, mystruct->exit1);
	if (!(mystruct->load_exit1))
		faill_textures(mystruct, 5);
	mystruct->load_x = mlx_texture_to_image(x42, mystruct->enemy);
	if (!(mystruct->load_x))
		faill_textures(mystruct, 6);
}
