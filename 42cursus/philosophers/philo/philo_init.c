/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:22:16 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/05 21:05:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_philo_data(t_philo_data *data, char **av)
{
	data->num_of_philo = ph_atoi(av[1]);
	if (data->num_of_philo < 1)
		return (-1);
	data->tt_die = ph_atoi(av[2]);
	data->tt_eat = ph_atoi(av[3]);
	data->tt_sleep = ph_atoi(av[4]);
	if (av[5])
		data->eat_count = ph_atoi(av[5]);
	else
		data->eat_count = __LONG_LONG_MAX__;
	return (0);
}

void	init_mutex(t_philo **philo, t_philo_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&(data->fork[i].key), NULL);
		pthread_mutex_init(&(philo[i]->eaten.key), NULL);
		pthread_mutex_init(&(philo[i]->dead.key), NULL);
		i++;
	}
}

int	init_philo(t_philo **philo, t_philo_data *data)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!(*philo))
		return (-1);
	memset(philo, 0, sizeof(t_mutex) * data->num_of_philo);
	data->fork = (t_mutex *)malloc(sizeof(t_mutex) * data->num_of_philo);
	if (!data->fork)
		return (-1);
	memset(data->fork, 0, sizeof(t_mutex) * data->num_of_philo);
	while (i < data->num_of_philo)
	{
		(*philo)[i].data = data;
		(*philo)[i].no = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % data->num_of_philo;
		i++;
	}
	init_mutex(philo, data);
	return (0);
}

void	*philo_task(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->no % 2) == 1)
		usleep(100);
	while (!ph_get_status(&(philo->dead)))
	{
		philo_eat(philo, philo->data);
		philo_sleep(philo, philo->data);
	}
	print_philo_status(philo, DEAD);
	return (NULL);
}

int	create_philos(t_philo **philo, t_philo_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_create(&philo[i]->tid, NULL, philo_task, philo[i]);
		i++;
	}
	return (0);
}
