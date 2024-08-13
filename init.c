/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by buozcan           #+#    #+#             */
/*   Updated: 2024/08/13 23:07:35 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->nbr_of_philo);
	if (main->philos == NULL)
		return (free(main->philos), EXIT_FAILURE);
	i = 0;
	while (i < main->nbr_of_philo)
		if (pthread_mutex_init(&main->forks[i++], NULL))
			return (free(main->philos), free(main->forks), EXIT_FAILURE);
}

static void	create_philo(t_main *main, t_philo *philo, int id)
{
	philo->id = id + 1;
	philo->right_fork = &main->forks[id];
	philo->left_fork = &main->forks[(id + 1) % main->nbr_of_philo];
	philo->state = EAT;
	philo->eat_count = 0;
	philo->start_time = main->start_time;
	philo->nbr_of_times_must_eat = main->nbr_of_times_must_eat;
	philo->time_to_die = main->time_to_die;
	philo->time_to_eat = main->time_to_eat;
	philo->time_to_sleep = main->time_to_sleep;
	philo->last_meal = get_current_time();
	pthread_create(philo->thread, NULL,
			&life_cycle, philo);
}

int	init_philos(t_main *main)
{
	int	i;

	main->philos = malloc(sizeof(t_philo) * main->nbr_of_philo);
	if (main->philos == NULL)
		return (EXIT_FAILURE);
	if (init_forks(main))
		return (EXIT_FAILURE);
	main->start_time = get_current_time();
	i = 0;
	while (i < main->nbr_of_philo)
	{
		create_philo(main, &main->philos[i], i);
		i++;
	}
	return (EXIT_SUCCESS);
}
