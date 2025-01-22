/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:51:15 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/22 11:39:03 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (i_p % 2 == 0)
	{
		while (pthread_mutex_lock((var->philo[i_p]).f_lft) != 0)
		{
			if (ft_philo_died(var, i_p) == 1)
				return (0);
		}
		ft_put_message(i_p, var, " has taken a fork\n");
		while ((var->philo[i_p]).f_rgt != NULL
			|| pthread_mutex_lock((var->philo[i_p]).f_rgt) != 0)
		{
			if (ft_philo_died(var, i_p) == 1)
			{
				pthread_mutex_unlock((var->philo[i_p]).f_lft);
				return (0);
			}
		}
		ft_put_message(i_p, var, " has taken a fork\n");
		return (1);
	}
	else
	{
		while (pthread_mutex_lock((var->philo[i_p]).f_rgt) != 0)
		{
			if (ft_philo_died(var, i_p) == 1)
				return (0);
		}
		ft_put_message(i_p, var, " has taken a fork\n");
		while ((var->philo[i_p]).f_lft != NULL
			|| pthread_mutex_lock((var->philo[i_p]).f_lft) != 0)
		{
			if (ft_philo_died(var, i_p) == 1)
			{
				pthread_mutex_unlock((var->philo[i_p]).f_rgt);
				return (0);
			}
		}
		ft_put_message(i_p, var, " has taken a fork\n");
		return (1);
	}
}

