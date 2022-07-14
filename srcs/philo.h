/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:23:00 by ekern             #+#    #+#             */
/*   Updated: 2022/07/14 14:25:22 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* INCLUDES */

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/* STRUCT */

typedef struct s_philo
{
	struct s_info *gen_info;  
	/* 2h de perdu parce que tu n'as pointer ce "gen_info" 
	sur la struct "info", Connard */
	pthread_t	thread_id;
	int			number_philo;
}				t_philo;

typedef struct	s_info
{
//	pthread_t	*tab[2];
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	struct timeval	set_time;
	t_philo		philosophers[10];
}				t_info;



/* SRCS */

void	*fc_philo(void *arg);
int 	ft_atoi(char *src);
void	fc_error(int error);
int	fc_print_action(int action, t_philo *philo);

#endif