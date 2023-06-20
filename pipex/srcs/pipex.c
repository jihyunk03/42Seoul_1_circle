/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 07:12:52 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		status;

	if (ac < 5)
	{
		ft_putstr_fd("argc error: more arguments are needed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pipex = init_pipex(ac, av, env);
	if (pipex == NULL)
		return (EXIT_FAILURE);
	return (0);
}
