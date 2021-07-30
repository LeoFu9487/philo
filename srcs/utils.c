/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:05:40 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 09:22:59 by yfu              ###   ########lyon.fr   */
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

void	ft_putstr_fd(char *str, int fd)
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
		ft_putstr_fd("Error: gettimeofday\n", 2);
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

/*
** if error return -1
*/
int	ft_atoi(char *str)
{
	long long int	ans;

	if (ft_strlen(str) < 1 || ft_strlen(str) > 10)
		return (-1);
	ans = 0LL;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			ans = 10LL * ans + (long long int)(*str - '0');
		else
			return (-1);
		++str;
	}
	if (ans > 2147483647LL)
		return (-1);
	return ((int)ans);
}
