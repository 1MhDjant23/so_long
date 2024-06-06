/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:34:46 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/06 12:56:58 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_long
{
	mlx_texture_t	*layer;
	mlx_texture_t	*pl_right;
	mlx_texture_t	*coin;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit1;
	mlx_image_t		*load_wall;
	mlx_image_t		*load_exit;
	mlx_image_t		*load_exit1;
	mlx_image_t		*pl;
	mlx_image_t		*collect;
	mlx_image_t		*load_layer;
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
	mlx_t			*x42;
}					t_long;

int		check_extension(char *av);
void	checking_map(t_long *game, char *av);
int		count_char(char *s);
void	free_array(char **str);
void	second_layer(t_long *my_struct, mlx_t *X42);
void	first_layer(t_long *my_struct, mlx_t *X42);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	load_image(t_long *mystruct, mlx_t *x42);
void	initialisation_win(t_long *my_struct);
void	move_player(t_long *strc, int mx, int my);
void	faill_textures(t_long *mystruct, int f);
char	*str_copy(char *dst, char *src);
void	free_mystruct(t_long *mystruct);
int		element_map(t_long *game);
int		check_line(char *line);
void	ex_it(char **str, t_long *game, int x);
void	free_textures(t_long *mystruct, int x);
void	close_widget(void *param);
void	print_win(void);
void	print_wast(void);

#endif