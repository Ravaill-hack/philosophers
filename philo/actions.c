/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/20 13:38:20 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_do_sth(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	pthread_mutex_lock(&(philo->var->mut_var));
	printf("je suis le thread %lu\n", philo->thread);
	pthread_mutex_unlock(&(philo->var->mut_var));
	return (phil);
}

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (pthread_mutex_lock((var->philo[i_p]).f_lft) != 0)
		return (0);
	ft_put_message(i_p, var, "has taken a fork\n");
	if (pthread_mutex_lock((var->philo[i_p]).f_rgt) != 0)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_lft);
		return (0);
	}
	ft_put_message(i_p, var, "has taken a fork\n");
	return (1);
}

int	ft_some1_died(t_var *var)
{
	int	res;

	pthread_mutex_lock(&(var->mut_var));
	if (var->some1_died == 1)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&(var->mut_var));
	return (res);
}

int	ft_philo_died(t_var *var, int i_p)
{
	pthread_mutex_lock(&(var->mut_var));
	if (var->philo[i_p].h_2_die <= ft_get_time_ms())
	{
		ft_put_message (i_p, var, "died\n");
		var->some1_died = 1;
		return (1);
	}
	pthread_mutex_unlock(&(var->mut_var));
	return (0);
}

void	ft_free_2_forks(t_var *var, int i_p)
{
	pthread_mutex_unlock((var->philo[i_p]).f_lft);
	pthread_mutex_unlock((var->philo[i_p]).f_rgt);
}

void	ft_is_thinking(t_var *var, int i_p)
{
	ft_put_message(i_p, var, "is thinking\n");
}

void	ft_is_sleeping(t_var *var, int i_p)
{
	ft_put_message(i_p, var, "is sleeping\n");
	usleep(1000 * var->t_2_slp);
}

void	ft_is_eating(t_var *var, int i_p)
{
	ft_put_message(i_p, var, "is eating\n");
	pthread_mutex_lock(&(var->mut_var));
	var->philo[i_p].h_end_last_meal = ft_get_time_ms() + var->t_2_eat - var->t_start;
	var->philo[i_p].h_2_die = var->philo[i_p].h_end_last_meal + var->t_2_die;
	pthread_mutex_unlock(&(var->mut_var));
	usleep(1000 * var->t_2_slp);
}
