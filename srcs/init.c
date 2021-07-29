/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:28:14 by yfu               #+#    #+#             */
/*   Updated: 2021/07/29 17:57:44 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(void)
{
	int	i;

	g_data.philo = malloc(g_data.number_of_philosophers * sizeof(t_philo));
	if (!g_data.philo)
	{
		ft_putstd_fd("Error : malloc\n", 2);
		return ;
	}
	g_data.program_end = 0;
	i = -1;
	while (++i < g_data.number_of_philosophers)
	{
		pthread_mutex_init(&g_data.philo[i].right_fork, NULL);
		if (g_data.number_of_philosophers == 1)
			break ;
		g_data.philo[i].left_fork = &(g_data.philo[(i + 1)
			% g_data.number_of_philosophers].right_fork);
	}
	pthread_mutex_init(&g_data.display_lock, NULL);
	pthread_mutex_init(&g_data.increment_lock, NULL);
}
