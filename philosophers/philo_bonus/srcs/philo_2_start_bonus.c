/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_start_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:06:20 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 19:44:12 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"


int	start_philo(t_philo *philo, t_data *data)
{
	int	i;
	int	status;

	i = 0;
	data->start_t = current_time();
	while (i < data->philosophers)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			exit (EXIT_FAILURE);
		else if (philo[i].pid == 0)
			start_routine();
	}
	i = 0;
	while (i < data->philosophers)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			exit_others();
		i++;
	}
}

static routine(t_philo *philo, t_data *data)
{

}
