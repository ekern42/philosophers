/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:19:09 by ekern             #+#    #+#             */
/*   Updated: 2022/07/14 14:13:58 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void fc_sleep(t_philo *philo)
{
//	printf("3\n");
	fc_print_action(2, philo);
//	printf("3\n");
//	usleep(info->time_to_sleep * 1000);
}

void	*fc_philo(void *arg)
{
	t_philo	*philo;
	
//	printf("fonctionne\n");
	philo = (t_philo *)arg;
//	printf("philo = %d\n", philo->info->nbr_of_philo);
//	printf("Die = %dms\n", philo->info->time_to_die);
//	printf("Eat = %dms\n", philo->info->time_to_eat);
//	printf("Sleep = %dms\n", philo->info->time_to_sleep);	
	fc_sleep(philo);
	printf("fonctionne\n");
	return(NULL);
}