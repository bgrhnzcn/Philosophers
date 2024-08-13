/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:55:41 by buozcan           #+#    #+#             */
/*   Updated: 2024/08/13 23:19:57 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_dead(t_philo *philo)
{
	if (((get_current_time() - philo->last_meal))
		> philo->time_to_die)
		philo->state = DEAD;
}

void	life_cycle(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
}

void	thread_handler(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->nbr_of_philo)
	{
		check_dead(&main->philos[i]);
		if (main->philos[i].state == DEAD)
		{
			printf("%llu\t%d died\n", get_current_time() - main->start_time,
				main->philos[i].id);
			main->is_loop_break = 1;
			break ;
		}
	}
}