/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:49:34 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 17:00:42 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr_fd(int num, int fd)
{
	int		arr[10];
	int		i;
	char	str[2];

	i = 0;
	while (num > 9)
	{
		arr[i++] = num % 10;
		num /= 10;
	}
	arr[i] = num;
	str[1] = 0;
	while (i >= 0)
	{
		str[0] = arr[i--] + '0';
		ft_putstr_fd(str, fd);
	}
}

void	ft_putstat(t_philo *philo, char *action)
{
	// need another lock
	ft_putnbr_fd(get_current_time_in_ms() - g_data.start_time, 2);
	ft_putstr_fd(" ", 2);
	ft_putnbr_fd(philo->id, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(action, 2);
	ft_putstr_fd("\n", 2);
}
