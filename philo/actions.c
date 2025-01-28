/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 11:23:36 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_var *var, int i_p)
{
	ft_take_2_forks(var, i_p);
	ft_put_message(i_p, &(var->m_m), " is eating\n");
	usleep(1000 * (int)(var->t_2_eat));
	var->philo[i_p].h_last = ft_get_time_ms();
	var->philo[i_p].h_2_die = var->philo[i_p].h_last + var->t_2_die;
	if (var->nb_eat_4_each != -1)
		var->philo[i_p].nb_meals += 1;
	pthread_mutex_unlock((var->philo[i_p]).f_lft);
	pthread_mutex_unlock((var->philo[i_p]).f_rgt);
	return (1);
}

void	ft_sleep(t_var *var, int i_p)
{
	ft_put_message(i_p, &(var->m_m), " is sleeping\n");
	usleep(1000 * (int)(var->t_2_slp));
}

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (i_p % 2 == 0)
		return (ft_lft_fork_first(var, i_p));
	else
		return (ft_rgt_fork_first(var, i_p));
	return (1);
}

int	ft_lft_fork_first(t_var *var, int i_p)
{
	pthread_mutex_lock((var->philo[i_p]).f_lft);
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	if (pthread_mutex_lock((var->philo[i_p]).f_rgt) != 0)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_lft);
		return (0);
	}
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	return (1);
}

int	ft_rgt_fork_first(t_var *var, int i_p)
{
	pthread_mutex_lock((var->philo[i_p]).f_rgt);
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	if (pthread_mutex_lock((var->philo[i_p]).f_lft) != 0)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_rgt);
		return (0);
	}
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	return (1);
}

