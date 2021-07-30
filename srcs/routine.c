/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:45:46 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 16:17:35 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_and_sleep(t_philo *philo)
{
	(void)philo;
}

void	*routine(void *ptr)
{
	t_philo		*philo;
	pthread_t	set_end_thread;

	philo = (t_philo*)ptr;
	philo->last_time_to_eat = get_current_time_in_ms(); // problem : maybe time won't be in order coz everybody starts with a different time
	if (pthread_create(&set_end_thread, NULL, set_program_end, philo))
	{
		ft_putstr_fd("Error: pthread_create\n", 2);
		return (NULL);
	}
	pthread_detach(set_end_thread);
	if (philo->id % 2)
		ft_sleep(g_data.time_to_eat);
	if (g_data.number_of_philosophers == 1)
	{
		ft_putstr_fd("has taken a fork\n", 2);
		ft_sleep(g_data.time_to_die);
	}
	else
		while (!g_data.program_end)
			eat_and_sleep(philo);
	return (NULL);
}
