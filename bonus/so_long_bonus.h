/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:15:30 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/09 23:04:06 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "/Users/mait-taj/Desktop/MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_long
{
	mlx_texture_t	*layer;
	mlx_texture_t	*ghost;
	mlx_texture_t	*coin;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit1;
	mlx_texture_t	*enemy;
	mlx_image_t		*load_wall;
	mlx_image_t		*load_x;
	mlx_image_t		*pl;
	mlx_image_t		*load_exit;
	mlx_image_t		*load_exit1;
	mlx_image_t		*collect;
	mlx_image_t		*load_layer;
	mlx_image_t		*moves;
	int				exit_px;
	int				exit_py;
	char			*map;
	char			*get_line;
	char			**split;
	char			*last_line;
	char			*first_line;
	int				fd;
	int				height_c;
	int				i;
	int				player;
	int				player_x;
	int				player_y;
	int				e;
	int				c;
	int				f_c;
	int				f_e;
	int				s;
	int				x;
	mlx_t			*x42;
}				t_long;

int		exten_sion(char *av);
void	map_check(t_long *game, char *av);
void	reading_file(t_long *game, char *av);
char	*str_copy(char *dst, char *src);
int		count_char(char *s);
void	free_mystruct(t_long *mystruct);
void	free_array(char **str);
int		line_check(char *line);
int		element(t_long *game);
void	window_init(t_long *my_struct);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	load_img(t_long *mystruct, mlx_t *x42);
void	move_pl(t_long *st, int mx, int my);
void	first_layer(t_long *st, mlx_t *X42);
void	second_layer(t_long *st, mlx_t *X42);
void	ex_it(char **str, t_long *game, int x);
void	free_mystruct(t_long *mystruct);
void	free_array(char **str);
void	faill_textures(t_long *mystruct, int f);
void	free_textures(t_long *mystruct, int x);
void	put_count_move(t_long *game, int count);
void	close_widget(void *param);
void	print_win(void);
void	print_wast(void);

#endif