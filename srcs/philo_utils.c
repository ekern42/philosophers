/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:40:48 by ekern             #+#    #+#             */
/*   Updated: 2022/07/14 14:28:20 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Au lieu d'utiliser la struct info, il faut utiliser la struct philo 
qui est directement liee a un seul philosopher c'est plus simple 
pour faire apparaitre le bon id
*/
int	fc_print_action(int action, t_philo *philo)
{
	struct timeval act_time;
	long	time;
//	long *id;
	int	no;
	
//	id = (long *)philo->thread_id;	//id du thread
	no = philo->number_philo;
	
	gettimeofday(&act_time, NULL);
	
	act_time.tv_sec -= philo->gen_info->set_time.tv_sec;
	act_time.tv_usec -= philo->gen_info->set_time.tv_usec;
	
	time = act_time.tv_usec / 1000;
	time += act_time.tv_sec * 1000;
	if (action == 2)
	{
		printf("TimeStamp : %dms | Philosopher number %i is sleeping\n", time, no);
	}
	return(1);
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
	exit(0);
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
