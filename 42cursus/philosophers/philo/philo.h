/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:01:28 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/02 23:24:55 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/time.h>

# define DEAD	0
# define FINISH	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define GRAB	5

typedef struct s_philo_data
{
	int	num_of_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_count;
}	t_philo_data;

typedef struct s_philo
{
	t_philo_data	*data;
	pthread_t		thread;
	int				no;
	int				left_fork;
	int				right_fork;
}	t_philo;

int	p_atoi(char *str);
int	terminate_philo(int flag, t_philo *philo);

#endif
