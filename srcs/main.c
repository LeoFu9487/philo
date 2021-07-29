/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:55:31 by yfu               #+#    #+#             */
/*   Updated: 2021/07/29 17:58:59 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	func(void *p)
{
	sleep(rand() % 5);
	printf("%d\n",*(int *)p);
	return (NULL);
}

int	main(int ac, char **av)
{
	if (parse(ac, av))
		return (1);
	init();
	
	// pthread_t	t[100];

	// for (int i = 0 ; i < 100 ; ++i)
	// {
	// 	pthread_create(&(t[i]), NULL, &func, &i);
	// }
	// for (int i = 0 ; i < 100 ; ++i)
	// {
	// 	pthread_join(t[i], NULL);
	// }
}
