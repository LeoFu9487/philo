/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:05:40 by yfu               #+#    #+#             */
/*   Updated: 2021/07/29 17:52:08 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putstd_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	pthread_mutex_lock(&g_data.display_lock);
	write(fd, str, ft_strlen(str));
	pthread_mutex_unlock(&g_data.display_lock);
}

unsigned int	get_current_time_in_ms(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) < 0)
	{
		ft_putstd_fd("Error gettimeofday\n", 2);
		return (-1);
	}
	return ((unsigned int)(current.tv_sec * 1000 + current.tv_usec / 1000));
}

void	ft_sleep(unsigned int ms)
{
	unsigned int	begin_time;

	if (ms < 500)
		usleep(ms * 1000);
	else
	{
		begin_time = get_current_time_in_ms();
		while (!g_data.program_end && get_current_time_in_ms() - begin_time < ms)
			usleep(1000);
	}
}
