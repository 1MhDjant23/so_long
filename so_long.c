/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:34:27 by mait-taj          #+#    #+#             */
/*   Updated: 2024/06/06 13:17:45 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_long	*mystruct;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == -1)
			return (write(2, "Invalid file\n", 13));
		mystruct = (t_long *)malloc(sizeof(t_long));
		if (!mystruct)
			exit(write(2, "Alloc Faill\n", 12));
		checking_map(mystruct, argv[1]);
		initialisation_win(mystruct);
	}
	return (0);
}
