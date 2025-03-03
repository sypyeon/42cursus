/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_terminate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:35:31 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/03 15:52:49 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	terminate_philo(int flag, t_philo **philo)
{
	free(*philo);
	if (flag == 1)
		write(2, "", 1);
	else
		return (write (2, "Unknown err\n", 13));
	return (flag);
}
