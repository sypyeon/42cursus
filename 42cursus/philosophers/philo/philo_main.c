/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:39:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/06 18:18:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_philo_data	data;

	if (ac != 5 && ac != 6)
		return (write (2, "insufficient arguments", 23));
	if (get_philo_data(&data, av) == -1)
		return (-1);
	if (init_philo(&philo, &data) == -1)
		return (-1);
	if (create_philos(philo, &data) == -1)
		return (-1);
	usleep (100);
	while (philo_observe(philo, &data) == RUN)
		usleep(200);
	return (0);
}
