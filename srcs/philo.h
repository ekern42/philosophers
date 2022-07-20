/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:23:00 by ekern             #+#    #+#             */
/*   Updated: 2022/07/20 13:45:23 by ekern            ###   ########.fr       */
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
	struct s_info	*gen_info;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				personnal_no;
	int				last_time_eaten;
	int				nbr_time_eaten;
}					t_philo;

typedef struct s_info
{
	int				nbr_of_philo;
	int				nbr_time_to_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				finish;	
	struct timeval	set_time;
	t_philo			*philosophers;
	pthread_t		countdown;
	pthread_mutex_t	*forks;
}					t_info;

/* MAIN SRCS */

void	*fc_philo(void *arg);
void	*fc_death_checker(void *arg);
void	fc_sleep(t_philo *philo);
void	fc_eat(t_philo *philo);
void	fc_think(t_philo *philo);
void	fc_dead(t_philo *philo);
void	fc_fork(t_philo *philo);

/* UTILS SRCS */

void	fc_error(int error);
int		fc_timestamp(t_philo *philo);
void	fc_print_action(int action, t_philo *philo);
int		ft_atoi(char *src);
void	fc_final_free(t_info *info);
void	fc_usleep(int time, t_philo *philo);
#endif