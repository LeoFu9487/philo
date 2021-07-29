/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:28:14 by yfu               #+#    #+#             */
/*   Updated: 2021/07/29 17:34:57 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
typedef struct s_philo
{
	pthread_t		pthread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_to_eat;
	int				program_end;
	pthread_mutex_t	display_lock;
	pthread_mutex_t	increment_lock;
}t_data;
*/

void    init(void)
{
	g_data.philo = malloc(g_data.number_of_philosophers * sizeof(t_philo));
	if (!g_data.philo)
	{
		ft_putstd_fd("Error : malloc\n", 2);
		return ;
	}
	g_data.program_end = 0;
	// todo (init phios, locks)
}
