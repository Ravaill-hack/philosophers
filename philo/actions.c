/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/22 14:22:43 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_do_sth(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if ((philo->n - 1) % 2 == 0)
		usleep(philo->var->t_2_eat * 1000);
	while (1)
	{
		if (ft_philo_died(philo->var, philo->n - 1) == 1)
			return (NULL);
		if (ft_eat(philo->var, philo->n - 1) == 0)
			return (NULL);
		if (ft_philo_died(philo->var, philo->n - 1) == 1
			|| ft_philo_ate_enough(philo->var, philo->n - 1) == 1)
			return (NULL);
		ft_sleep(philo->var, philo->n - 1);
		if (ft_philo_died(philo->var, philo->n - 1) == 1)
			return (NULL);
		ft_put_message(philo->n - 1, philo->var, " is thinking\n");
		if (ft_philo_died(philo->var, philo->n - 1) == 1)
			return (NULL);
	}
	return (phil);
}

int	ft_eat(t_var *var, int i_p)
{
	ft_take_2_forks(var, i_p);
	ft_put_message(i_p, var, " is eating\n");
	pthread_mutex_lock(&(var->mut_var));
	usleep(1000 * var->t_2_eat);
	var->philo[i_p].h_end_last_meal = ft_get_time_ms();
	var->philo[i_p].h_2_die = var->philo[i_p].h_end_last_meal + var->t_2_die;
	if (var->nb_eat_4_each != -1)
		var->philo[i_p].nb_meals += 1;
	pthread_mutex_unlock((var->philo[i_p]).f_lft);
	pthread_mutex_unlock((var->philo[i_p]).f_rgt);
	pthread_mutex_unlock(&(var->mut_var));
	return (1);
}

void	ft_sleep(t_var *var, int i_p)
{
	pthread_mutex_lock(&(var->mut_var));
	ft_put_message(i_p, var, " is sleeping\n");
	usleep(1000 * var->t_2_slp);
	pthread_mutex_unlock(&(var->mut_var));
}

