/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/22 11:17:39 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_died(t_var *var, int i_p)
{
	pthread_mutex_lock(&(var->mut_var));
	if (var->philo[i_p].h_2_die <= (ft_get_time_ms()))
	{
		ft_put_message (i_p, var, " died\n");
		pthread_mutex_unlock(&(var->mut_var));
		return (1);
	}
	pthread_mutex_unlock(&(var->mut_var));
	return (0);
}
int	ft_philo_ate_enough(t_var *var, int i_p)
{
	pthread_mutex_lock(&(var->mut_var));
	if (var->nb_eat_4_each == -1)
	{
		pthread_mutex_unlock(&(var->mut_var));
		return (0);
	}
	if (var->philo[i_p].nb_meals >= var->nb_eat_4_each)
	{
		ft_put_message (i_p, var, " ate all the meals needed\n");
		pthread_mutex_unlock(&(var->mut_var));
		return (1);
	}
	pthread_mutex_unlock(&(var->mut_var));
	return (0);
}

int	ft_join(t_var *var)
{
	int	i;

	i = 0;
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
	pthread_mutex_destroy(&(var->mut_var));
	free (var->mut_forks);
	var->mut_forks = NULL;
	free (var->philo);
	var->philo = NULL;
	free (var);
	var = NULL;
	return (0);
}
