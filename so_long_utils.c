/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:01:30 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/08 00:31:46 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_textures(t_long *mystruct, int x)
{
	mlx_delete_texture(mystruct->layer);
	mlx_delete_texture(mystruct->exit1);
	mlx_delete_texture(mystruct->coin);
	mlx_delete_texture(mystruct->wall);
	mlx_delete_texture(mystruct->pl_right);
	free_array(mystruct->split);
	free(mystruct->map);
	mlx_close_window(mystruct->x42);
	free(mystruct->x42);
	if (x == 1)
		print_win();
	if (x == -1)
		exit(write(1, "EXIT\n", 5));
}

void	faill_textures(t_long *mystruct, int f)
{
	if (f != 0)
	{
		if (mystruct->layer && (f == 1 || f == 2 || f == 3 || f == 4 || f == 5))
			mlx_delete_texture(mystruct->layer);
		if (mystruct->pl_right && (f == 2 || f == 3 || f == 4 || f == 5))
			mlx_delete_texture(mystruct->pl_right);
		if (mystruct->coin && (f == 3 || f == 4 || f == 5))
			mlx_delete_texture(mystruct->coin);
		if (mystruct->wall && (f == 4 || f == 5))
			mlx_delete_texture(mystruct->wall);
		if (mystruct->exit && f == 5)
			mlx_delete_texture(mystruct->exit);
	}
	if (mystruct->split)
		free_array(mystruct->split);
	if (mystruct->first_line)
		free(mystruct->first_line);
	if (mystruct->map)
		free(mystruct->map);
	mlx_close_window(mystruct->x42);
	free(mystruct);
	exit(write(2, "PNG NOT FOUND\n", 14));
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
	if (mystruct)
		free(mystruct);
	ft_printf("Error\n");
	exit(write(2, "IV map\n", 7));
}
