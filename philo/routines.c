/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:52:53 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 10:57:12 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *v)
{
	t_var	*var;

	var = (t_var *)v;
	while (1)
	{
		usleep(100);
		pthread_mutex_lock(&(var->m_f));
		if (var->nb_finish == var->nb_philo)
		{
			pthread_mutex_unlock(&(var->m_f));
			return (ft_set_end(var));
		}
		pthread_mutex_unlock(&(var->m_f));
		pthread_mutex_lock(&(var->m_d));
		if (var->dead == 1)
		{
			pthread_mutex_unlock(&(var->m_d));
			return (ft_set_end(var));
		}
		pthread_mutex_unlock(&(var->m_d));
	}
	return (var);
}

void	*ft_do_sth(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->var->nb_philo == 1)
		return (ft_do_one(philo));
	while (1)
	{
		if (ft_check_philo(philo) == 1)
			return (NULL);
		ft_eat(philo->var, philo->n - 1);
		if (ft_check_philo(philo) == 1)
			return (NULL);
		ft_sleep(philo->var, philo->n - 1);
		if (ft_check_philo(philo) == 1)
			return (NULL);
		ft_put_message(philo->n - 1, &(philo->var->m_m), " is thinking\n");
	}
	return (phil);
}

void	*ft_do_one(t_philo *philo)
{
	ft_put_message(philo->n - 1, &(philo->var->m_m), " has taken a fork\n");
	usleep(philo->var->t_2_die * 1000);
	ft_check_philo_death(philo->var, philo->n - 1);
	return (NULL);
}

void	*ft_set_end(t_var *var)
{
	pthread_mutex_lock(&(var->m_e));
	var->end = 1;
	pthread_mutex_unlock(&(var->m_e));
	return (NULL);
}
