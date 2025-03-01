/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:39:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/02 00:19:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_t	*thread;
	int			philo_num;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
	int			eat_count;
	
	if (ac != 6)
		return (write (2, "insufficient arguments", 23));
	// av[1] = number_of_philosophers and number_of_thread
	philo_num = p_atoi(av[1]);
	if (philo_num < 1)
		return (write (2, "should have at least one philo", 31));
	thread = (pthread_t *)malloc(sizeof(pthread_t) * philo_num);
	if (!thread)
		return (write (2, "could not allocate", 19));
	
	// av[2] = time_to_die
	tt_die = p_atoi(av[2]);
	if (tt_die < 0)
		return (write (2, "invalid time to die", 13));
	// av[3] = time_to_eat
	tt_eat = p_atoi(av[3]);
	if (tt_eat < 0)
		return (write (2, "invalid time to eat", 13));
	// av[4] = time_to_sleep
	tt_sleep = p_atoi(av[4]);
	if (tt_sleep < 0)
		return (write (2, "invalid time to sleep", 13));
	// av[5] = [number_of_times_each_philosopher_must_eat]
	eat_count = p_atoi(av[2]);
	if (eat_count < 0)
		return (0);
		
}
