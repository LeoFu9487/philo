/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <yfu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:55:56 by yfu               #+#    #+#             */
/*   Updated: 2021/07/30 13:28:23 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*
** allowed functions :
** memset
** printf
** malloc
** free
** write
** usleep
** gettimeofday
** pthread_create
** pthread_detach
** pthread_join
** pthread_mutex_init
** pthread_mutex_destroy
** pthread_mutex_lock
** pthread_mutex_unlock
*/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
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

t_data	g_data;

/*___________________________________________________________________________*/
/*
** main.c
*/

int					create_thread(void);

/*___________________________________________________________________________*/
/*
** utils.c
*/

int					ft_strlen(char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_sleep(unsigned int ms);
int					ft_atoi(char *str);
unsigned int		get_current_time_in_ms(void);

/*___________________________________________________________________________*/

/*
** init.c
*/

int		   			init(void);

/*___________________________________________________________________________*/

/*
** parse.c
*/

int					parse(int ac, char **av);

/*___________________________________________________________________________*/

/*
** routine.c
*/

void				*routine(void *ptr);

/*___________________________________________________________________________*/

/*
** exit.c
*/

void				exit_free(void);

/*___________________________________________________________________________*/

#endif