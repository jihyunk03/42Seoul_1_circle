/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:30:36 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/13 17:42:22 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_leaks(void);

int	main(int ac, char **av)
{
	t_maps	*maps;

	if (ac != 2)
		return (EXIT_FAILURE);	// error: only 1 file exist
	maps = init_maps();
	check_map(maps, av[1]);
	return (EXIT_SUCCESS);
}

void	check_leaks(void)
{
	system("leaks --quiet so_long");
}
