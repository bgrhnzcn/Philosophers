/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:33 by buozcan           #+#    #+#             */
/*   Updated: 2024/08/13 19:32:23 by buozcan          ###   ########.fr       */
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
	THINK
}	t_state;

typedef struct s_philo
{
	pthread_t	*thread;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		nbr_of_times_must_eat;
	unsigned long long	start_time;
	t_state				state;
}	t_philo;

typedef struct s_main
{
	unsigned long		number_of_philosophers;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		nbr_of_times_must_eat;
	unsigned long long	start_time;
	char				*forks;
	t_philo				*philos;
}	t_main;

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					init_philos(t_main *main);
unsigned long long	get_current_time();
void				life_cycle(t_philo *philo);

#endif
