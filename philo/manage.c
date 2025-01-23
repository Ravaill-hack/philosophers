/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/23 17:27:18 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_died(t_var *var, int i_p)
{
	if (var->philo[i_p].h_2_die <= ft_get_time_ms())
	{
		ft_put_message (i_p, &(var->m_m), " died\n");
		pthread_mutex_lock(&var->m_d);
		var->dead = 1;
		pthread_mutex_unlock(&var->m_d);
		return (1);
	}
	return (0);
}

int	ft_some_1_died(t_var *var)
{
	pthread_mutex_lock(&var->m_d);
	if (var->dead == 1)
	{
		pthread_mutex_unlock(&var->m_d);
		return (1);
	}
	pthread_mutex_unlock(&var->m_d);
	return (0);
}

int	ft_philo_ate_enough(t_var *var, int i_p)
{
	if (var->nb_eat_4_each == -1)
		return (0);
	if (var->philo[i_p].nb_meals >= var->nb_eat_4_each)
	{
		pthread_mutex_lock(&(var->m_f));
		var->nb_finish ++;
		pthread_mutex_unlock(&(var->m_f));
		return (1);
	}
	return (0);
}

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
