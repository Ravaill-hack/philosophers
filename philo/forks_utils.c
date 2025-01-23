/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:51:15 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/23 13:02:15 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (i_p % 2 == 0)
	{
		pthread_mutex_lock((var->philo[i_p]).f_lft);
		ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
		if (pthread_mutex_lock((var->philo[i_p]).f_rgt) != 0)
		{
			pthread_mutex_unlock((var->philo[i_p]).f_lft);
			return (0);
		}
		ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock((var->philo[i_p]).f_rgt);
		ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
		if (pthread_mutex_lock((var->philo[i_p]).f_lft) != 0)
		{
			pthread_mutex_unlock((var->philo[i_p]).f_rgt);
			return (0);
		}
		ft_put_message(i_p, &(var->m_m), " has taken a fork\n");
	}
	return (1);
}

