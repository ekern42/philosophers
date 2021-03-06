/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:40:48 by ekern             #+#    #+#             */
/*   Updated: 2022/07/20 13:58:19 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fc_usleep(int time, t_philo *philo)
{
	int	precise_usleep;

	precise_usleep = (fc_timestamp(philo) + time) * 1000;
	while ((fc_timestamp(philo) * 1000) != precise_usleep)
		usleep(100);
}

int	fc_timestamp(t_philo *philo)
{
	int				time;
	struct timeval	act_time;

	gettimeofday(&act_time, NULL);
	act_time.tv_sec -= philo->gen_info->set_time.tv_sec;
	act_time.tv_usec -= philo->gen_info->set_time.tv_usec;
	time = act_time.tv_usec / 1000;
	time += act_time.tv_sec * 1000;
	return (time);
}

void	fc_print_action(int action, t_philo *philo)
{
	int	time;
	int	no;

	time = fc_timestamp(philo);
	no = philo->personnal_no;
	if (action == 1)
		printf("%d\t%i\thas taken a fork\n", time, no);
	else if (action == 2)
		printf("%d\t%i\tis eating\n", time, no);
	else if (action == 3)
		printf("%d\t%i\tis sleeping\n", time, no);
	else if (action == 4)
		printf("%d\t%i\tis thinking\n", time, no);
	else if (action == 5)
		printf("%d\t%i\tdied\n", time, no);
}

void	fc_error(int error)
{
	if (error == 1)
		printf("Arg should be only a number\n");
	else if (error == 2)
		write(1, "Wrong nbr of args\n", 18);
	else if (error == 3)
		printf("Args should be higher than 0\n");
	else if (error == 4)
		printf("Max 100 philosophers\n");
	exit (0);
}

int	ft_atoi(char *src)
{
	int	a;
	int	b;
	int	c;

	a = -1;
	b = 1;
	c = 0;
	if (src[0] == '-')
	{
		b = -1;
		a++;
	}
	while (src[++a] != '\0')
	{
		if ((src[a] > 47 && src[a] < 58))
		{
			c += src[a];
			c -= 48;
			if (src[a + 1] != '\0')
				c *= 10;
		}
		else
			fc_error(1);
	}
	return (c * b);
}
