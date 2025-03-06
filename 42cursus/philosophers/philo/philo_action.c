/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:14:40 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/06 22:06:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo *philo, t_philo_data *data, t_mutex *right_fork)
{
	long	eaten;

	ph_set_status(right_fork, philo->no);
	print_philo_status(philo, GRAB);
	print_philo_status(philo, EAT);
	ph_set_status(&(philo->starve_time), current_time() + data->tt_die);
	schrodingers_philo(philo, data->tt_eat);
	eaten = ph_get_status(&(philo->eaten));
	ph_set_status(&(philo->eaten), eaten + 1);
	ph_set_status(right_fork, 0);
}

static void	philo_grab_fork(t_philo *philo, t_philo_data *data)
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	long	value;

	if (philo->no == data->num_of_philo)
	{
		right_fork = &(data->fork[philo->left_fork]);
		left_fork = &(data->fork[philo->right_fork]);
	}
	else
	{
		left_fork = &(data->fork[philo->left_fork]);
		right_fork = &(data->fork[philo->right_fork]);
	}
	while (!ph_get_status(&(philo->dead)))
	{
		value = ph_get_status(left_fork);
		if (value == 0 || value == philo->no)
		{
			if (value == 0)
				print_philo_status(philo, GRAB);
			ph_set_status(left_fork, philo->no);
			value = ph_get_status(right_fork);
			if (value == 0)
			{
				philo_eat(philo, data, right_fork);
				ph_set_status(left_fork, 0);;
				break ;
			}
		}
	}
}

static void	philo_sleep(t_philo *philo, t_philo_data *data)
{
	if (ph_get_status(&(philo->dead)))
		return ;
	print_philo_status(philo, SLEEP);
	schrodingers_philo(philo, data->tt_sleep);
}

void	*philo_task(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->no % 2) == 1)
		usleep(1000);
	while (!ph_get_status(&(philo->dead)))
	{
		print_philo_status(philo, THINK);
		philo_grab_fork(philo, philo->data);
		philo_sleep(philo, philo->data);
	}
	return (NULL);
}
