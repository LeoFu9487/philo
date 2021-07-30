/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:45:46 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 16:58:30 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_and_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	ft_putstat(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	ft_putstat(philo, "has taken a fork");
	ft_putstat(philo, "is eating");
	philo->last_time_to_eat = get_current_time_in_ms();
	if (++(philo->meal_eaten) == g_data.number_of_times_to_eat)
	{
		pthread_mutex_lock(&g_data.increment_lock);
		++(g_data.number_of_full_philosophers);
		pthread_mutex_unlock(&g_data.increment_lock);
	}
	ft_sleep(g_data.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
	ft_putstat(philo, "is sleeping");
	ft_sleep(g_data.time_to_sleep);
	ft_putstat(philo, "is thinking");
}
// problem : does philo need to stop eating after having enough meals ?

void	*routine(void *ptr)
{
	t_philo		*philo;
	pthread_t	set_end_thread;

	philo = (t_philo*)ptr;
	philo->last_time_to_eat = g_data.start_time;
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
		ft_putstat(philo, "has taken a fork");
		ft_sleep(g_data.time_to_die);
	}
	else
		while (!g_data.program_end)
			eat_and_sleep(philo);
	return (NULL);
}
