/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:31:15 by ekern             #+#    #+#             */
/*   Updated: 2022/07/18 16:37:28 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fc_loop(t_philo *philo)
{
	philo->nbr_time_eaten = 0;
	while (1)
	{
		fc_fork(philo);
		fc_eat(philo);
		if (philo->nbr_time_eaten == philo->gen_info->nbr_time_to_eat)
		{
			printf("No %d | End loop\n", philo->personnal_no);
			return ;
		}
		fc_sleep(philo);
		fc_think(philo);
	}
	printf("No %d | End loop\n", philo->personnal_no);
}

void	*fc_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_time_eaten = fc_timestamp(philo);
	if (philo->personnal_no % 2 == 0)
		usleep(philo->gen_info->time_to_eat * 1000);
	fc_loop(philo);
	return (NULL);
}

void	*fc_death_checker(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *)arg;
	i = 0;
	while (1)
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
					return (NULL);
				}
			}
			i++;
		}
	}
	return (NULL);
}
