/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_program_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:43:14 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 16:59:03 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*set_program_end(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!g_data.program_end)
	{
		if (g_data.number_of_full_philosophers == g_data.number_of_philosophers)
		{
			pthread_mutex_lock(&g_data.increment_lock);
			ft_putstr_fd("Everybody is full now\n", 2);
			g_data.program_end = 1;
			pthread_mutex_unlock(&g_data.increment_lock);
		}
		else if (get_current_time_in_ms() - philo->last_time_to_eat >= (unsigned int)g_data.time_to_die)
		{
			pthread_mutex_lock(&g_data.increment_lock);
			ft_putstat(philo, "died");
			g_data.program_end = 1;
			pthread_mutex_unlock(&g_data.increment_lock);
		}
	}
	return (NULL);
}
