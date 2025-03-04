/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:01:28 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/04 21:48:28 by sipyeon          ###   ########.fr       */
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

# define MSG	"has taken a fork\0is eating\0is sleeping\0is thinking\0died"

typedef enum e_msg
{
	GRAB = 0,
	EAT = 17,
	SLEEP = 27,
	THINK = 39,
	DEAD = 51,
}	t_msg;

typedef struct s_mutex
{
	long			status;
	pthread_mutex_t	key;
}	t_mutex;

typedef struct s_philo_data
{
	int				num_of_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				eat_count;
	t_mutex			*fork;
	pthread_mutex_t	print;
}	t_philo_data;

typedef struct s_philo
{
	t_philo_data	*data;
	pthread_t		tid;
	int				no;
	int				left_fork;
	int				right_fork;
	int				ready_to_eat;
	t_mutex			eaten;
	t_mutex			dead;
}	t_philo;

int	ph_atoi(char *str);
int	terminate_philo(int flag, t_philo **philo);

// printf("%d  \n", philo->no);
// has taken a fork
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died

#endif
