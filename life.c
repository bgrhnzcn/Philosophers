/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:55:41 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/03 22:10:22 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(long time)
{
	long	dest_time;

	dest_time = get_current_time() + time;
	while (get_current_time() < dest_time)
		usleep(500);
}

void	check_dead(t_philo *philo)
{
	if ((get_current_time() - philo->last_meal) > philo->time_to_die)
		philo->state = DEAD;
}

int	to_do_continue(t_philosopher *philo)
{
	if (check_and_unlock(philo, 0) == 0)
		return (0);
	pthread_mutex_lock(philo->r_fork);
	if (check_and_unlock(philo, 1) == 0)
		return (0);
	my_printf(philo, "has taken a fork");
	if (check_and_unlock(philo, 1) == 0)
		return (0);
	pthread_mutex_lock(philo->l_fork);
	if (check_and_unlock(philo, 2) == 0)
		return (0);
	my_printf(philo, "has taken a fork");
	my_printf(philo, "is eating");
	if (check_and_unlock(philo, 2) == 0)
		return (0);
	return (1);
}

void	to_do(t_philo *philo)
{
	while (1)
	{
		if (to_do_continue(philo) == 0)
			break ;
		philo_eating(philo);
		if (check_and_unlock(philo, 2) == 0)
			break ;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		my_printf(philo, "is sleeping");
		ft_sleep(philo, philo->time_to_sleep);
		if (check_and_unlock(philo, 0) == 0)
			break ;
		my_printf(philo, "is thinking");
		if (check_and_unlock(philo, 0) == 0)
			break ;
	}
}

int		life_cycle_hlpr(t_philo *philo)
{
	if (check_and_unlock(philo, 0) == 0)
		return (EXIT_FAILURE);
	pthread_mutex_lock(philo->right_fork);
	if (check_and_unlock(philo, 1) == 0)
		return (EXIT_FAILURE);
	my_printf(philo, "has taken a fork");
	if (check_and_unlock(philo, 1) == 0)
		return (EXIT_FAILURE);
	pthread_mutex_lock(philo->left_fork);
	if (check_and_unlock(philo, 2) == 0)
		return (EXIT_FAILURE);
	my_printf(philo, "has taken a fork");
	my_printf(philo, "is eating");
	if (check_and_unlock(philo, 2) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	*life_cycle(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	if (philo->id % 2 == 0)
		usleep(750);
	while (philo->state != DEAD)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
}

int	thread_manager(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->nbr_of_philo)
	{
		check_dead(&main->philos[i]);
		pthread_mutex_lock(&main->print);
		if (main->philos[i].state == DEAD)
		{
			printf("%llu\t%d died\n", get_run_time(main),
				main->philos[i].id);
			main->is_loop_break = 1;
			pthread_mutex_unlock(&main->print);
			return (EXIT_FAILURE);
		}
		pthread_mutex_unlock(&main->print);
		i++;
	}
	return (EXIT_SUCCESS);
}