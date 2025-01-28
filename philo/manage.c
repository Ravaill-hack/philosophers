/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 17:00:58 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_join(t_var *var)
{
	int	i;

	i = 0;
	pthread_join(var->death_checker, NULL);
	while (i < var->nb_philo)
	{
		pthread_join(var->philo[i].thread, NULL);
		i++;
	}
	return (0);
}

int	ft_end_cycle(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->nb_philo)
	{
		pthread_mutex_destroy(&(var->mut_forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(var->m_e));
	pthread_mutex_destroy(&(var->m_m));
	pthread_mutex_destroy(&(var->m_d));
	pthread_mutex_destroy(&(var->m_f));
	free (var->mut_forks);
	var->mut_forks = NULL;
	free (var->philo);
	var->philo = NULL;
	free (var);
	var = NULL;
	return (0);
}

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (i_p % 2 == 0)
		return (ft_lft_fork_first(var, i_p));
	else
		return (ft_rgt_fork_first(var, i_p));
	return (-1);
}

int	ft_sleep_while_sleeping(long time, t_var *var, int i_p)
{
	long	start;
	long	end;
	int		ind;

	start = ft_get_time_ms();
	end = start + time;
	ind = 0;
	while (ft_get_time_ms() <= end)
	{
		ind = ft_check_philo(&var->philo[i_p]);
		if (ind == 1 || ind == 2)
			return (ind);
		usleep(1000);
	}
	return (0);
}

int	ft_sleep_while_eating(long time, t_var *var)
{
	long	start;
	long	end;

	start = ft_get_time_ms();
	end = start + time;
	while (ft_get_time_ms() <= end)
	{
		if (ft_check_end(var) == 1)
			return (1);
		usleep(1000);
	}
	return (0);
}
