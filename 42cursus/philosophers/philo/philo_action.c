/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:14:40 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/05 19:54:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	philo_sleep(t_philo *philo, t_philo_data *data)
{
	schrodingers_philo(philo, data->tt_sleep);
}
