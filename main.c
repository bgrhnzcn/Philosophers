/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:19 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/03 16:49:12 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_philo(t_main *main)
{
	(void)main;
}

static int	parse_field(char *argv)
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

static int	parse_args(t_main *main, char **argv, int argc)
{
	main->nbr_of_philo = parse_field(argv[1]);
	if (!main->nbr_of_philo)
		return (EXIT_FAILURE);
	main->time_to_die = parse_field(argv[2]);
	if (!main->time_to_die)
		return (EXIT_FAILURE);
	main->time_to_eat = parse_field(argv[3]);
	if (!main->time_to_eat)
		return (EXIT_FAILURE);
	main->time_to_sleep = parse_field(argv[4]);
	if (!main->time_to_sleep)
		return (EXIT_FAILURE);
	if (argc == 6)
	{
		main->nbr_of_times_must_eat = parse_field(argv[5]);
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
		return (exit_philo(&main), EXIT_FAILURE);
	main.is_loop_break = 0;
	while (!main.is_loop_break)
	{
		if (thread_manager(&main))
			exit_philo(&main);
	}
	return (EXIT_SUCCESS);
}
