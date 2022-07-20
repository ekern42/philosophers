/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:31:15 by ekern             #+#    #+#             */
/*   Updated: 2022/07/20 13:46:05 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fc_loop(t_philo *philo)
{
	philo->nbr_time_eaten = 0;
	while (philo->nbr_time_eaten != philo->gen_info->nbr_time_to_eat && \
	philo->gen_info->finish == 0)
	{
		fc_fork(philo);
		fc_eat(philo);
		fc_sleep(philo);
		fc_think(philo);
	}
	return ;
}

void	*fc_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->last_time_eaten = fc_timestamp(philo);
	if (philo->personnal_no % 2 == 0)
		usleep(philo->gen_info->time_to_eat * 1000);
	fc_loop(philo);
	return (NULL);
}

static int	fc_finish_checker(t_info *info)
{
	int	i;

	i = 0;
	while (info->philosophers[i].nbr_time_eaten == info->nbr_time_to_eat)
	{
		if (i == info->nbr_of_philo - 1)
			return (1);
		i++;
	}
	return (0);
}

void	*fc_death_checker(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *)arg;
	while (info->finish == 0)
	{
		i = 0;
		while (i < info->nbr_of_philo)
		{
			if (info->philosophers[i].nbr_time_eaten != info->nbr_time_to_eat)
			{
				if (fc_timestamp(&info->philosophers[i]) \
				- info->time_to_die > info->philosophers[i].last_time_eaten)
				{
					fc_dead(&info->philosophers[i]);
					info->finish = 1;
				}
			}
			i++;
		}
		info->finish += fc_finish_checker(info);
	}
	return (NULL);
}
