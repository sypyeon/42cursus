/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:01:28 by sipyeon           #+#    #+#             */
/*   Updated: 2025/03/06 02:34:02 by sipyeon          ###   ########.fr       */
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

# define STOP	0
# define RUN	1

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
	unsigned long	eat_count;
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
	t_mutex			starve_time;
	t_mutex			eaten;
	t_mutex			dead;
}	t_philo;

int				ph_atoi(char *str);

int				get_philo_data(t_philo_data *data, char **av);
int				init_philo(t_philo **philo, t_philo_data *data);
int				create_philos(t_philo *philo, t_philo_data *data);

void			*philo_task(void *arg);
void			philo_sleep(t_philo *philo, t_philo_data *data);
void			philo_eat(t_philo *philo, t_philo_data *data);

long			ph_get_status(t_mutex *mutex);
void			ph_set_status(t_mutex *mutex, long philo_num);
void			print_philo_status(t_philo *philo, t_msg status);

void			schrodingers_philo(t_philo *philo, int time);
unsigned long	current_time(void);

int				philo_observe(t_philo *philo, t_philo_data *data);

// printf("%d  \n", philo->no);
// has taken a fork
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died

#endif
