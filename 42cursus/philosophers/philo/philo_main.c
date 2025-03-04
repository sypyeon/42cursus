/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:39:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/04 18:59:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_reach_fork(t_philo *philo, t_philo_data *data)
{
	t_mutex	left_fork;
	t_mutex	right_fork;
	
	left_fork = data->fork[philo->left_fork];
	right_fork = data->fork[philo->right_fork];
	while (1)
	{
		if (left_fork.status != 0 && right_fork.status != 0)
		{
			pthread_mutex_lock(&left_fork.key);
			pthread_mutex_lock(&right_fork.key);
			left_fork.status = philo->no;
			right_fork.status = philo->no;
			philo->ready_to_eat = 1;
			break ;
		}
	}
}
void	ph_eat_and_release(t_philo *philo, t_philo_data *data)
{
	t_mutex	left_fork;
	t_mutex	right_fork;
	
	left_fork = data->fork[philo->left_fork];
	right_fork = data->fork[philo->right_fork];
	if (philo->ready_to_eat)
	{
		usleep(philo->data->tt_eat);
		left_fork.status = 0;
		right_fork.status = 0;
		philo->ready_to_eat = 0;
		pthread_mutex_unlock(&left_fork.key);
		pthread_mutex_unlock(&right_fork.key);
	}
}

void	*philo_task(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;

	if ((philo->no % 2) == 0)
		usleep(100);
	while (1)
	{
		if(philo->data->eat_count <= philo->eaten.status)
			break ;
		ph_reach_fork(philo, philo->data);
		ph_eat_and_release(philo, philo->data);
	}
}

int	get_philo_data(t_philo_data *data, char **av)
{
	if (data->num_of_philo = p_atoi(av[1]) < 1);
	data->tt_die = p_atoi(av[2]);
	data->tt_eat = p_atoi(av[3]);
	data->tt_sleep = p_atoi(av[4]);
	if (av[5])
		data->eat_count = p_atoi(av[5]);
	else
		data->eat_count = -1;
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

int	create_philos(t_philo **philo, t_philo_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_create(philo[i]->tid, NULL, philo_task, philo[i]);
		i++;
	}
	return (0);
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

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_philo_data	data;

	if (ac != 5 && ac != 6)
		return (write (2, "insufficient arguments", 23));
	if (get_philo_data(&data, av) == -1)
		return (terminate_philo(1, philo));
	if (init_philo(&philo, &data) == -1)
		return (terminate_philo(1, philo));
	if (create_philos(&philo, &data) == -1)
		return (-1);
}
