/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/28 16:05:51 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_eat(t_var *var, int i_p)
{
	int	i;

	i = ft_take_2_forks(var, i_p);
	if (i == 1 || i == 2)
		return (i);
	ft_put_message(i_p, &(var->m_m), " is eating\n");
	i = ft_sleep_while_eating(var->t_2_eat, var);
	if (i == 1)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_lft);
		pthread_mutex_unlock((var->philo[i_p]).f_rgt);
		return (1);
	}
	var->philo[i_p].h_last = ft_get_time_ms();
	var->philo[i_p].h_2_die = var->philo[i_p].h_last + var->t_2_die;
	pthread_mutex_unlock((var->philo[i_p]).f_lft);
	pthread_mutex_unlock((var->philo[i_p]).f_rgt);
	if (var->nb_eat_4_each != -1)
		var->philo[i_p].nb_meals += 1;
	if (var->philo[i_p].nb_meals == var->nb_eat_4_each)
	{
		pthread_mutex_lock(&var->m_f);
		var->nb_finish ++;
		pthread_mutex_unlock(&var->m_f);
		return (2);
	}	
	return (0);
}

int	ft_sleep(t_var *var, int i_p)
{
	ft_put_message(i_p, &(var->m_m), " is sleeping\n");
	return (ft_sleep_while_sleeping(var->t_2_slp, var, i_p));
}

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (i_p % 2 == 0)
		return (ft_lft_fork_first(var, i_p));
	else
		return (ft_rgt_fork_first(var, i_p));
	return (-1);
}

int	ft_lft_fork_first(t_var *var, int i_p)
{
	int	i;

	i = -1;
	pthread_mutex_lock((var->philo[i_p]).f_lft);
	i = ft_check_philo(&var->philo[i_p]);
	if (i == 1 || i == 2)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_lft);
		return (i);
	}
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	if (pthread_mutex_lock((var->philo[i_p]).f_rgt) != 0)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_lft);
		return (-1);
	}
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	return (0);
}

int	ft_rgt_fork_first(t_var *var, int i_p)
{
	int	i;

	i = -1;
	pthread_mutex_lock((var->philo[i_p]).f_rgt);
	i = ft_check_philo(&var->philo[i_p]);
	if (i == 1 || i == 2)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_rgt);
		return (i);
	}
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	if (pthread_mutex_lock((var->philo[i_p]).f_lft) != 0)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_rgt);
		return (-1);
	}
	ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	return (0);
}
