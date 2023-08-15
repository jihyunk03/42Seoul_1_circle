/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:32:07 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/16 04:55:52 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*start_routine(void *ph);
static void	*_one_philo_routine(t_philo *philo, t_data *data);
static void	_monitoring_dead(t_data *data);

int	start_philo(t_philo *philo, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->start_t = current_time();
	while (i < 2)
	{
		j = i;
		while (j < data->philosophers)
		{
			if (pthread_create(&philo[j].tid, NULL, start_routine, &philo[j]))
				return (error_exit(philo, data, PHILO_ERR));
			j += 2;
		}
		usleep(data->eat_t * 500);
		i++;
	}
	_monitoring_dead(data);
	free_philo(philo, data->philosophers);
	free_data(data);
	return (EXIT_SUCCESS);
}

static void	*start_routine(void *ph)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ph;
	data = philo->data;
	if (data->philosophers == 1)
		return (_one_philo_routine(philo, data));
	philo->last_eat = current_time();
	while (TRUE)
	{
		if (_ph_eat(philo, data) == END)
			break ;
		if (_ph_sleep_and_think(philo, data) == END)
			break ;
		usleep(100);
	}
}

static void	*_one_philo_routine(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->f_state[philo->left]);
	data->forks[philo->left] = USING;
	print_message(philo, FORK);
	pthread_mutex_unlock(&data->f_state[philo->left]);
	while (current_time() - data->start_t < data->die_t)
		usleep(500);
	print_dead(philo, data);
	pthread_mutex_lock(&data->f_state[philo->left]);
	data->forks[philo->left] = AVAILABLE;
	pthread_mutex_unlock(&data->f_state[philo->left]);
	return (NULL);
}

static void	_monitoring_dead(t_data *data)
{
	while (TRUE)
	{
		if (someone_dead(data) == TRUE)
			return ;
		usleep(200);
	}
}
