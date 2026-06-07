/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:03:16 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/06 22:45:36 by sipyeon          ###   ########.fr       */
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

void	ph_set_status(t_mutex *mutex, long status)
{
	pthread_mutex_lock(&(mutex->key));
	mutex->status = status;
	pthread_mutex_unlock(&(mutex->key));
}

void	print_philo_status(t_philo *philo, t_msg status)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("%ld %d %s\n", current_time(), philo->no, &MSG[status]);
	pthread_mutex_unlock(&(philo->data->print));
}
