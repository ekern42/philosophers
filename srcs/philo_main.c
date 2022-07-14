/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:25:57 by ekern             #+#    #+#             */
/*   Updated: 2022/07/14 14:27:21 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Ligne 30, le usleep permet de finir les pthreads avant que le thread priincipal
	se termine, parce que s'il se termine avant, les pthread n'auront pas le temps
	de finir leur programme. Ou mettre une boucle while(1)
*/
static int fc_thread(t_info *info)
{
	int	i;
	i = -1;
	
	while (++i < info->nbr_of_philo)
	{
		info->philosophers[i].gen_info = info;
		info->philosophers[i].number_philo = (i + 1);
		pthread_create(&info->philosophers[i].thread_id, NULL, fc_philo, &info->philosophers[i]);	
		usleep(10);
	}
	return (1);
}

static int	fc_init(t_info *info, char **av)
{
	info->nbr_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if ((info->nbr_of_philo < 1) | (info->time_to_die < 1) | (info->time_to_eat < 1) | (info->time_to_sleep < 1))
		fc_error(3);
	else if (info->nbr_of_philo > 100)
		fc_error(4);
	gettimeofday(&info->set_time, NULL);
//	printf("%d \n", info->nbr_of_philo);
//	printf("%dms \n", info->time_to_die);
//	printf("%dms \n", info->time_to_eat);
//	printf("%dms \n", info->time_to_sleep);
	return (1);
}

int	main(int ac, char **av)
{
	t_info info;
	
	if (ac != 5)
		fc_error(2);
	fc_init(&info, av);
	fc_thread(&info);
	while (1);
	return (0);
}