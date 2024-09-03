/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:33 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/03 16:47:13 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK,
	DEAD = -1
}	t_state;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		nbr_of_times_must_eat;
	unsigned long		eat_count;
	unsigned long		last_meal;
	unsigned long long	start_time;
	t_state				state;
}	t_philo;

typedef struct s_main
{
	long		nbr_of_philo;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		nbr_of_times_must_eat;
	unsigned long long	start_time;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	char				is_loop_break;
}	t_main;

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					init_philos(t_main *main);
unsigned long long	get_current_time(void);
unsigned long long	get_run_time(t_main *main);
void				*life_cycle(void *philo);
int					thread_manager(t_main *main);

#endif
