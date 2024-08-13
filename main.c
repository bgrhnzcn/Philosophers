/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:19 by buozcan           #+#    #+#             */
/*   Updated: 2024/08/13 19:32:21 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_field(t_main *main, char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (ft_atoi(argv));
}

int	parse_args(t_main *main, char **argv, int argc)
{
	main->number_of_philosophers = parse_field(main, argv[1]);
	if (!main->number_of_philosophers)
		return (EXIT_FAILURE);
	main->time_to_die = parse_field(main, argv[2]);
	if (!main->time_to_die)
		return (EXIT_FAILURE);
	main->time_to_eat = parse_field(main, argv[3]);
	if (!main->time_to_eat)
		return (EXIT_FAILURE);
	main->time_to_sleep = parse_field(main, argv[4]);
	if (!main->time_to_sleep)
		return (EXIT_FAILURE);
	if (argc == 6)
	{
		main->nbr_of_times_must_eat = parse_field(main, argv[5]);
		if (!main->nbr_of_times_must_eat)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (parse_args(&main, argv, argc))
		return (EXIT_FAILURE);
	if (init_philos(&main))
		return (EXIT_FAILURE);
}
