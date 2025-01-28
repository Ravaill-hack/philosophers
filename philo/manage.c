/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 10:53:52 by lmatkows         ###   ########.fr       */
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
