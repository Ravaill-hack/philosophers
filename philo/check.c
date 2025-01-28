/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:47:10 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 13:51:55 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_philo(t_philo *philo)
{
	if (ft_check_philo_death(philo->var, philo->n - 1) == 1
		|| ft_check_philo_nb_meals(philo->var, philo->n - 1) == 1
		|| ft_check_end(philo->var) == 1)
		return (1);
	return (0);
}

int	ft_check_death(t_var *var)
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

int	ft_check_end(t_var *var)
{
	pthread_mutex_lock(&var->m_e);
	if (var->end == 1)
	{
		pthread_mutex_unlock(&var->m_e);
		return (1);
	}
	pthread_mutex_unlock(&var->m_e);
	pthread_mutex_lock(&var->m_f);
	if (var->nb_finish >= var->nb_philo)
	{
		pthread_mutex_unlock(&var->m_f);
		return (1);
	}
	pthread_mutex_unlock(&var->m_f);
	return (ft_check_death(var));
}

int	ft_check_philo_nb_meals(t_var *var, int i_p)
{
	if (var->nb_eat_4_each == -1)
		return (0);
	pthread_mutex_lock(&(var->m_f));
	if (var->philo[i_p].nb_meals >= var->nb_eat_4_each)
	{
		var->nb_finish ++;
		pthread_mutex_unlock(&(var->m_f));
		return (1);
	}
	pthread_mutex_unlock(&(var->m_f));
	return (0);
}

int	ft_check_philo_death(t_var *var, int i_p)
{
	if (var->philo[i_p].h_2_die <= ft_get_time_ms())
	{
		pthread_mutex_lock(&var->m_d);
		var->dead = 1;
		usleep(1000);
		ft_put_message (i_p, &(var->m_m), " died\n");
		pthread_mutex_unlock(&var->m_d);
		return (1);
	}
	return (0);
}
