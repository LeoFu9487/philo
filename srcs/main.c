/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:55:31 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 15:42:43 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** IF error return -1, else return 0
*/
int	create_thread(void)
{
	int	i;

	i = -1;
	while (++i < g_data.number_of_philosophers)
	{
		if (pthread_create(&g_data.philo[i].thread_id, NULL,
				routine, &g_data.philo[i]))
		{
			ft_putstr_fd("Error: pthread_create\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	g_data.program_end = 0;
	if (parse(ac, av))
	{
		ft_putstr_fd("Error: arguments\n", 2);
		return (1);
	}
	if (init() || create_thread())
		return (1);
	exit_free();
	return (0);
}
