/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:39:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/03 16:41:54 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_task()
{
	
}

int	get_philo_data(t_philo_data *data, char **av)
{
	if (data->num_of_philo = p_atoi(av[1]) < 1); // = number_of_philosophers and number_of_thread
	data->tt_die = p_atoi(av[2]); // = time_to_die (in milliseconds)
	data->tt_eat = p_atoi(av[3]); // = time_to_eat (in milliseconds)
	data->tt_sleep = p_atoi(av[4]); // = time_to_sleep (in milliseconds)
	if (av[5])
		data->eat_count = p_atoi(av[5]); // = [number_of_times_each_philosopher_must_eat] (optional argument)
	else
		data->eat_count = -1;
}

int	init_philo(t_philo **philo, t_philo_data *data)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!(*philo))
		return (-1);
	while (i < data->num_of_philo)
	{
		philo[i]->data = data;
		philo[i]->no = i;
		philo[i]->left_fork = i;
		philo[i]->right_fork = i + 1;
		if (data->num_of_philo == i + 1)
			philo[i]->right_fork = 0;
		if (pthread_create(philo[i]->tid, NULL, philo_task, philo[i]))
			return (-1);
		philo[i]->dead = 0;
		i++;
	}
	return (0);
}
	
int	main(int ac, char **av)
{
	t_philo			**philo;
	t_philo_data	*data;

	if (ac != 5 && ac != 6)
		return (write (2, "insufficient arguments", 23));
	if (get_philo_data(data, av) == -1)
		return (terminate_philo(1, philo));
	if (init_philo(philo, data) == -1)
		return (terminate_philo(1, philo));
}
