/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:13:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/06 22:43:10 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	while (current_time() < wait && ph_get_status(&(philo->dead)) == 0)
		usleep(200);
}
