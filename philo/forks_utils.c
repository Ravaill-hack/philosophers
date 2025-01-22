/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:51:15 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/22 14:08:58 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_2_forks(t_var *var, int i_p)
{
	if (pthread_mutex_lock((var->philo[i_p]).f_lft) != 0
		/*&& var->philo[i_p].f_lft != NULL*/)
		return (0);
	if (var->philo[i_p].f_lft != NULL)
		ft_put_message(i_p, var, " has taken a fork lft\n");
	if (pthread_mutex_lock((var->philo[i_p]).f_rgt) != 0
		/*&& var->philo[i_p].f_rgt != NULL*/)
	{
		pthread_mutex_unlock((var->philo[i_p]).f_lft);
		return (0);
	}
	if (var->philo[i_p].f_rgt != NULL)
		ft_put_message(i_p, var, " has taken a fork rgt\n");
	return (1);
}

