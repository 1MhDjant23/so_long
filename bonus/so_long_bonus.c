/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:06:10 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/09 23:23:54 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exten_sion(char *av)
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

int	main(int argc, char **argv)
{
	t_long	*mystruct;

	if (argc == 2)
	{
		if (exten_sion(argv[1]) == -1)
		{
			ft_printf("Error\n");
			return (write(2, "Invalid file\n", 13));
		}
		mystruct = malloc(sizeof(t_long));
		if (!mystruct)
			exit(write(2, "Alloc Faill\n", 12));
		map_check(mystruct, argv[1]);
		window_init(mystruct);
	}
	return (0);
}
