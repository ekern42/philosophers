/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:19:09 by ekern             #+#    #+#             */
/*   Updated: 2022/07/20 13:53:21 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fc_sleep(t_philo *philo)
{
	if (philo->nbr_time_eaten != philo->gen_info->nbr_time_to_eat && \
		philo->gen_info->finish == 0)
	{
		fc_print_action(3, philo);
		fc_usleep(philo->gen_info->time_to_sleep, philo);
	}
}

void	fc_eat(t_philo *philo)
{
	if (philo->nbr_time_eaten != philo->gen_info->nbr_time_to_eat && \
		philo->gen_info->finish == 0)
	{
		fc_print_action(2, philo);
		philo->last_time_eaten = fc_timestamp(philo);
		fc_usleep(philo->gen_info->time_to_eat, philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->nbr_time_eaten++;
	}
}

void	fc_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (philo->nbr_time_eaten != philo->gen_info->nbr_time_to_eat && \
		philo->gen_info->finish == 0)
	{
		fc_print_action(1, philo);
	}
	pthread_mutex_lock(philo->right_fork);
	if (philo->nbr_time_eaten != philo->gen_info->nbr_time_to_eat && \
		philo->gen_info->finish == 0)
	{
		fc_print_action(1, philo);
	}
}

void	fc_think(t_philo *philo)
{
	if (philo->nbr_time_eaten != philo->gen_info->nbr_time_to_eat && \
		philo->gen_info->finish == 0)
	{
		fc_print_action(4, philo);
	}
}

void	fc_dead(t_philo *philo)
{
	fc_print_action(5, philo);
}
