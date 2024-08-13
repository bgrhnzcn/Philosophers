/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by buozcan           #+#    #+#             */
/*   Updated: 2024/08/13 19:32:16 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_main *main)
{
	
}

int	init_philos(t_main *main)
{
	int	i;

	main->philos = malloc(sizeof(t_philo) * main->number_of_philosophers);
	if (main->philos == NULL)
		return (EXIT_FAILURE);
	main->forks = malloc(sizeof(char) * main->number_of_philosophers);
	if (main->philos == NULL)
		return (free(main->philos), EXIT_FAILURE);
	main->start_time = get_current_time();
	i = 0;
	while (i < main->number_of_philosophers)
	{
		main->philos[i].state = EAT;
		main->philos[i].start_time = main->start_time;
		main->philos[i].nbr_of_times_must_eat = main->nbr_of_times_must_eat;
		main->philos[i].time_to_die = main->time_to_die;
		main->philos[i].time_to_eat = main->time_to_eat;
		main->philos[i].time_to_sleep = main->time_to_sleep;
		pthread_create(main->philos[i].thread, NULL,
				&life_cycle, &main->philos[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
