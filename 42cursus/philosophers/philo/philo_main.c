/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:39:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/04 23:39:44 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ph_get_status(t_mutex *mutex)
{
	long	value;

	pthread_mutex_lock(&(mutex->key));
	value = mutex->status;
	pthread_mutex_unlock(&(mutex->key));
	return (value);
}

void	ph_set_status(t_mutex *mutex, long philo_num)
{
	pthread_mutex_lock(&(mutex->key));
	mutex->status = philo_num;
	pthread_mutex_unlock(&(mutex->key));
}

void	print_philo_status(t_philo *philo, t_msg status)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("%d %s", philo->no, MSG[status]);
	pthread_mutex_unlock(&(philo->data->print));
}

void	philo_eat(t_philo *philo, t_philo_data *data)
{
	t_mutex	left_fork;
	t_mutex	right_fork;
	long	value;

	left_fork = data->fork[philo->left_fork];
	right_fork = data->fork[philo->right_fork];
	while (1)
	{
		value = ph_get_status(&left_fork);
		if (value == 0)
		{
			ph_set_status(&left_fork, philo->no);
			value = ph_get_status(&right_fork);
			if (value == 0)
			{
				ph_set_status(&right_fork, philo->no);
				philo->ready_to_eat = 1;
				print_philo_status(philo, EAT);
				schrodingers_philo(philo, data->tt_eat);
				break ;
			}
		}
	}
}

unsigned long	current_time(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	schrodingers_philo(t_philo *philo, int time)
{
	unsigned long	wait;
	
	wait = current_time() + time;
	while (current_time() < wait && !ph_get_status(&philo->dead))
		usleep(200);
}

void	philo_sleep(t_philo *philo, t_philo_data *data)
{
	schrodingers_philo(philo, data->tt_sleep);
}

void	philo_think(t_philo *philo, t_philo_data *data)
{
	schrodingers_philo(philo, data->tt_);
}

void	*philo_task(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;

	if ((philo->no % 2) == 1)
		usleep(100);
	while (!ph_get_status(&(philo->dead)))
	{
		philo_eat(philo, philo->data);
		philo_sleep(philo, philo->data);
		philo_think(philo, philo->data);
	}
	print_philo_status(philo, DEAD);
	return (NULL);
}

int	get_philo_data(t_philo_data *data, char **av)
{
	if (data->num_of_philo = ph_atoi(av[1]) < 1);
	data->tt_die = ph_atoi(av[2]);
	data->tt_eat = ph_atoi(av[3]);
	data->tt_sleep = ph_atoi(av[4]);
	if (av[5])
		data->eat_count = ph_atoi(av[5]);
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
