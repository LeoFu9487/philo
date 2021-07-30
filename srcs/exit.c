/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:26:23 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 13:36:23 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_free(void)
{
	int i;

	i = -1;
	while (++i < g_data.number_of_philosophers)
	{
		if (pthread_join(g_data.philo[i].thread_id, NULL))
		{
			ft_putstr_fd("Error: pthread_join\n", 2);
			return ;
		}
		pthread_mutex_destroy(&g_data.philo[i].right_fork);
	}
	free(g_data.philo);
	pthread_mutex_destroy(&g_data.display_lock);
	pthread_mutex_destroy(&g_data.increment_lock);
}
