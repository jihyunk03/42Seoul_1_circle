/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:56:37 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/16 06:04:47 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		errno;

	if (ac < 5 || ac > 6)
		return (error_message("Error: invalid arguments\n"));

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	errno = init_data(data, ac, av);
	if (errno != SUCCESS)
		return (error_exit(NULL, data, errno));
	philo = init_philo(data);
	if (philo == NULL)
		return (error_exit(NULL, data, ALLOC_FAIL));
	return (start_philo(philo, data));
}
