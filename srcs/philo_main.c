/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:25:57 by ekern             #+#    #+#             */
/*   Updated: 2022/07/19 12:11:30 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Ligne 30, le usleep permet de finir les pthreads
 	avant que le thread priincipal
	se termine, parce que s'il se termine avant, les pthread n'auront pas le temps
	de finir leur programme. Ou mettre une boucle while(1)
*/
static int	fc_init_philo(t_info *info, int i)
{
	info->philosophers[i].gen_info = info;
	info->philosophers[i].personnal_no = (i + 1);
	pthread_mutex_init(&info->forks[i], NULL);
	info->philosophers[i].left_fork = &info->forks[i];
	if (i + 1 == info->nbr_of_philo)
		info->philosophers[i].right_fork = &info->forks[0];
	else
		info->philosophers[i].right_fork = &info->forks[i + 1];
	return (1);
}

static int	fc_init_thread(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nbr_of_philo)
	{
		fc_init_philo(info, i);
		pthread_create(&info->philosophers[i].thread_id, \
		NULL, fc_philo, &info->philosophers[i]);
	}
	pthread_create(&info->countdown, NULL, fc_death_checker, info);
	return (1);
}

static int	fc_gen_init(t_info *info, char **av, int ac)
{
	info->nbr_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->nbr_time_to_eat = ft_atoi(av[5]);
	else
		info->nbr_time_to_eat = -1;
	if ((info->nbr_of_philo < 1) | (info->time_to_die < 1) | \
	(info->time_to_eat < 1) | (info->time_to_sleep < 1))
		fc_error(3);
	else if (info->nbr_of_philo > 100)
		fc_error(4);
	info->philosophers = malloc(sizeof(t_philo) * info->nbr_of_philo);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nbr_of_philo);
	gettimeofday(&info->set_time, NULL);
	return (1);
}

void	fc_final_free(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nbr_of_philo - 1)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->philosophers);
	free(info->forks);
}

int	main(int ac, char **av)
{
	t_info	info;
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		fc_error(2);
	fc_gen_init(&info, av, ac);
	fc_init_thread(&info);
	pthread_join(info.countdown, NULL);
//	printf("blblblblblb\n");
	while (pthread_join(info.philosophers[i].thread_id, NULL))
	i++;
	fc_final_free(&info);
	return (0);
}
