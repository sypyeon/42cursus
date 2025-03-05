/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_observer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:56:13 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/05 21:09:47 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	terminate_philos(t_philo **philo, t_philo_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (ph_get_status(&philo[i]->dead) != 1)
		{
			ph_set_status(&philo[i]->dead, 1);
			pthread_join(philo[i]->tid, NULL);
		}
	}
}

static void	philo_starve_to_death(t_philo *philo)
{
	ph_set_status(&philo->dead, 1);
	pthread_join(philo->tid, NULL);
	print_philo_status(philo, DEAD);
}

int	philo_observe(t_philo **philo, t_philo_data *data)
{
	unsigned long	min_eaten;
	int		i;

	min_eaten = __LONG_MAX__;
	i = 0;
	while (i < data->num_of_philo)
	{
		if (current_time() >= (unsigned long)ph_get_status(&philo[i]->starve_time))
		{
			philo_starve_to_death(philo[i]);
			terminate_philos(philo, data);
			return (STOP);
		}
		if (min_eaten >= (unsigned long)ph_get_status(&philo[i]->eaten))
			min_eaten = ph_get_status(&philo[i]->eaten);
		i++;
	}
	if (min_eaten >= data->eat_count)
	{
		terminate_philos(philo, data);
		return (STOP);
	}
	return (RUN);
}
