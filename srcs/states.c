/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:19:09 by ekern             #+#    #+#             */
/*   Updated: 2022/07/18 16:39:53 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fc_sleep(t_philo *philo)
{
	fc_print_action(3, philo);
	usleep(philo->gen_info->time_to_sleep * 1000);
//	fc_usleep(philo->gen_info->time_to_sleep, philo);
}

void	fc_eat(t_philo *philo)
{
	fc_print_action(2, philo);
	philo->last_time_eaten = fc_timestamp(philo);
//	fc_usleep(philo->gen_info->time_to_eat, philo);
	usleep(philo->gen_info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->nbr_time_eaten++;
}

void	fc_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	fc_print_action(1, philo);
	pthread_mutex_lock(philo->right_fork);
	fc_print_action(1, philo);
}

void	fc_think(t_philo *philo)
{
	fc_print_action(4, philo);
}

void	fc_dead(t_philo *philo)
{
	fc_print_action(5, philo);
//	fc_final_free(philo->gen_info);
//	pthread_detach(philo->gen_info->countdown);
}
