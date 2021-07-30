/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:28:14 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 16:54:52 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutex_init(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
	{
		ft_putstr_fd("Error: pthread_mutex_init\n", 2);
		return (-1);
	}
	return (0);
}

int	init(void)
{
	int	i;

	g_data.start_time = get_current_time_in_ms();
	g_data.number_of_full_philosophers = 0;
	g_data.philo = malloc(g_data.number_of_philosophers * sizeof(t_philo));
	if (!g_data.philo)
	{
		ft_putstr_fd("Error: malloc\n", 2);
		return (-1);
	}
	i = -1;
	while (++i < g_data.number_of_philosophers)
	{
		g_data.philo[i].id = i + 1;
		g_data.philo[i].meal_eaten = 0;
		if (mutex_init(&g_data.philo[i].right_fork))
			return (-1);
		if (g_data.number_of_philosophers == 1)
			break ;
		g_data.philo[i].left_fork = &(g_data.philo[(i + 1)
				% g_data.number_of_philosophers].right_fork);
	}
	if (mutex_init(&g_data.increment_lock) || mutex_init(&g_data.display_lock))
		return (-1);
	return (0);
}
