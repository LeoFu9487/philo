/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:31:07 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 14:40:54 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** If error return -1, else return 0
*/
int	parse(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (-1);
	g_data.number_of_times_to_eat = -1;
	if (ac == 6)
	{
		g_data.number_of_times_to_eat = ft_atoi(av[5]);
		if (g_data.number_of_times_to_eat < 0)
			return (-1);
	}
	g_data.number_of_philosophers = ft_atoi(av[1]);
	g_data.time_to_die = ft_atoi(av[2]);
	g_data.time_to_eat = ft_atoi(av[3]);
	g_data.time_to_sleep = ft_atoi(av[4]);
	if (g_data.number_of_philosophers < 0 || g_data.time_to_die < 0
		|| g_data.time_to_eat < 0 || g_data.time_to_sleep < 0)
		return (-1);
	return (0);
}
