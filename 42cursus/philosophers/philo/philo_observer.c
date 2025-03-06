/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_observer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:56:13 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/06 21:42:31 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	terminate_philos(t_philo *philo, t_philo_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (ph_get_status(&(philo[i].dead)) == 0)
		{
			ph_set_status(&(philo[i].dead), 1);
			pthread_join(philo[i].tid, NULL);
		}
		i++;
	}
	free(philo);
	free(data->fork);
}

static void	philo_starve_to_death(t_philo *philo)
{
	ph_set_status(&philo->dead, 1);
	pthread_join(philo->tid, NULL);
	print_philo_status(philo, DEAD);
}

int	philo_observe(t_philo *philo, t_philo_data *data)
{
	int	min_eaten;
	int	i;

	min_eaten = __INT_MAX__;
	i = 0;
	while (i < data->num_of_philo)
	{
		if (current_time() >= (unsigned long)ph_get_status(&philo[i].starve_time))
		{
			philo_starve_to_death(&philo[i]);
			terminate_philos(philo, data);
			return (STOP);
		}
		if (min_eaten >= (int)ph_get_status(&philo[i].eaten))
			min_eaten = ph_get_status(&philo[i].eaten);
		i++;
	}
	if (data->eat_count == -1)
		return (RUN);
	else if (min_eaten >= data->eat_count)
	{
		terminate_philos(philo, data);
		return (STOP);
	}
	return (RUN);
}
